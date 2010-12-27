#include "Precompile.h"
#include "JavaClassScanner.h"
#include "model/Namespace.h"
#include "model/Class.h"
#include "model/Method.h"
#include "model/Field.h"
#include "model/Type.h"
#include "model/IntrinsicTypes.h"
#include "model/FQClassType.h"

namespace {
	
	namespace qi=boost::spirit::qi;
	namespace ascii=boost::spirit::ascii;

	template <typename Iterator>
	struct jclass_type_grammar
	{
		typedef jclass_type_grammar<Iterator> jclass_type_grammar_t;
		
		typedef qi::rule<Iterator, ascii::space_type> qi_rule_t;
		typedef qi::rule<Iterator, std::string(), ascii::space_type> qi_rule_string_t;
		
		typedef function< shared_ptr<model::Type> ()> create_type_t;
		typedef function< shared_ptr<model::Type> (std::size_t)> create_ndim_array_type_t;

		jclass_type_grammar(
			shared_ptr<model::Namespace> const &rns,
			shared_ptr<model::Class> const &c
		)
		: m_root_ns(rns)
		, m_class(c)
		{
			type_g=
				(
					non_array_type_g[bind(&jclass_type_grammar_t::on_parse_non_array_type, this)] |
					array_1dim_g[bind(&jclass_type_grammar_t::on_parse_ndim_array_type, this, 1)] |
					array_2dim_g[bind(&jclass_type_grammar_t::on_parse_ndim_array_type, this, 2)] |
					array_3dim_g[bind(&jclass_type_grammar_t::on_parse_ndim_array_type, this, 3)] 
				)
				;

			array_1dim_g=
				(qi::lit('[') >> non_array_type_g);

			array_2dim_g=
				(qi::lit("[[") >> non_array_type_g);

			array_3dim_g=
				(qi::lit("[[[") >> non_array_type_g);

			non_array_type_g=
				intrinsic_type_g |
				fqc_type_g;

			intrinsic_type_g=
				qi::lit('B')[bind(&jclass_type_grammar_t::on_parse_intrinsic<model::kByte>, this)] |
				qi::lit('C')[bind(&jclass_type_grammar_t::on_parse_intrinsic<model::kChar>, this)] |
				qi::lit('D')[bind(&jclass_type_grammar_t::on_parse_intrinsic<model::kDouble>, this)] |
				qi::lit('F')[bind(&jclass_type_grammar_t::on_parse_intrinsic<model::kFloat>, this)] |
				qi::lit('I')[bind(&jclass_type_grammar_t::on_parse_intrinsic<model::kInt>, this)] |
				qi::lit('J')[bind(&jclass_type_grammar_t::on_parse_intrinsic<model::kLong>, this)] |
				qi::lit('S')[bind(&jclass_type_grammar_t::on_parse_intrinsic<model::kShort>, this)] |
				qi::lit('V')[bind(&jclass_type_grammar_t::on_parse_intrinsic<model::kVoid>, this)] |
				qi::lit('Z')[bind(&jclass_type_grammar_t::on_parse_intrinsic<model::kBoolean>, this)];

			fqc_type_g=
				fqc_name_g[bind(&jclass_type_grammar_t::on_parse_fqc, this, _1)];

			fqc_name_g=
				qi::lexeme['L'>+(qi::char_-';')>';'];
		}

		template <model::eIntrinsicType IT>
		shared_ptr<model::Type> create_intrinsic_type()
		{
			return shared_ptr<model::Type>(new typename model::IntrinsicTypeTraits<IT>::ValueType());
		}

		template <model::eIntrinsicType IT>
		shared_ptr<model::NDimArrayType> create_intrinsic_ndim_array_type(std::size_t nd)
		{
			return shared_ptr<model::NDimArrayType>(
				new typename model::IntrinsicNDimArrayType<IT>(
					shared_ptr<typename model::IntrinsicTypeTraits<IT>::ValueType>(
						new  typename model::IntrinsicTypeTraits<IT>::ValueType
					),
					nd
				)
			);
		}

		template <model::eIntrinsicType IT>
		void on_parse_intrinsic()
		{
			m_current_create_type=bind(&jclass_type_grammar_t::create_intrinsic_type<IT>, this);
			m_current_create_ndim_array_type=bind(&jclass_type_grammar_t::create_intrinsic_ndim_array_type<IT>, this, _1);
		}

		shared_ptr<model::Type> create_fqc_type(std::string fqc_name)
		{
			algorithm::replace_all(fqc_name,"/",".");
			algorithm::replace_all(fqc_name,"$",".");
			shared_ptr<model::Class> pFQC=shared_ptr<model::Class>(
				m_root_ns->find_entity(fqc_name),
				detail::dynamic_cast_tag()
			);
			BOOST_ASSERT(pFQC);
			if(pFQC)
				return shared_ptr<model::Type>(new model::FQClassType(pFQC));
			return shared_ptr<model::Type>();
		}

		shared_ptr<model::Type> create_fqc_ndim_array_type(std::string fqc_name, std::size_t nd)
		{
			algorithm::replace_all(fqc_name,"/",".");
			algorithm::replace_all(fqc_name,"$",".");
			shared_ptr<model::Class> pFQC=shared_ptr<model::Class>(
				m_root_ns->find_entity(fqc_name),
				detail::dynamic_cast_tag()
			);
			BOOST_ASSERT(pFQC);
			if(pFQC)
				return shared_ptr<model::Type>(
					new model::FQClassNDimArrayType(
						shared_ptr<model::FQClassType>(new model::FQClassType(pFQC)),
						nd
					)
				);
			return shared_ptr<model::Type>();
		}

		void on_parse_fqc(std::string cn)
		{
			m_current_create_type=bind(&jclass_type_grammar_t::create_fqc_type, this, cn);
			m_current_create_ndim_array_type=bind(&jclass_type_grammar_t::create_fqc_ndim_array_type, this, cn, _1);
		}

		void on_parse_non_array_type()
		{
			m_create_type=m_current_create_type;
		}

		void on_parse_ndim_array_type(std::size_t nd)
		{
			m_create_type=bind(m_current_create_ndim_array_type, nd);
		}

		shared_ptr<model::Namespace>	m_root_ns;
		shared_ptr<model::Class>		m_class;

		create_type_t					m_current_create_type;
		create_ndim_array_type_t		m_current_create_ndim_array_type;

		create_type_t					m_create_type;

		qi_rule_t						type_g, intrinsic_type_g,
										non_array_type_g, array_1dim_g, array_2dim_g, array_3dim_g, fqc_type_g;
		
		qi_rule_string_t				fqc_name_g;
	};
	
	template <typename Iterator>
	struct jclass_method_grammar
		: jclass_type_grammar<Iterator>
		, qi::grammar<Iterator, ascii::space_type>
	{
		typedef jclass_type_grammar<Iterator> jclass_type_grammar_t;
		typedef jclass_method_grammar<Iterator> jclass_method_grammar_t;
		
		jclass_method_grammar(
			shared_ptr<model::Namespace> const &rns,
			shared_ptr<model::Class> const &c
		)
		: jclass_type_grammar_t(rns,c)
		, jclass_method_grammar_t::base_type(signature_g)
		{
			signature_g=
				"(" >>
				arguments_g >>
				")" >>
				return_value_g;

			arguments_g=
				*(jclass_type_grammar_t::type_g[bind(&jclass_method_grammar_t::on_parse_argument, this)]);

			return_value_g=
				jclass_type_grammar_t::type_g[bind(&jclass_method_grammar_t::on_parse_return_value, this)];
		}

		void on_parse_argument()
		{
			m_method_argument_types.push_back(m_create_type);
		}

		void on_parse_return_value()
		{
			m_method_return_type=m_create_type;
		}

		std::vector<jclass_type_grammar_t::create_type_t>	m_method_argument_types;
		jclass_type_grammar_t::create_type_t				m_method_return_type;
				
		jclass_type_grammar_t::qi_rule_t					signature_g, arguments_g, return_value_g;
	};

	template <typename Iterator>
	struct jclass_field_grammar
		: jclass_type_grammar<Iterator>
		, qi::grammar<Iterator, ascii::space_type>
	{
		typedef jclass_type_grammar<Iterator> jclass_type_grammar_t;
		typedef jclass_field_grammar<Iterator> jclass_field_grammar_t;

		jclass_field_grammar(
			shared_ptr<model::Namespace> const &rns,
			shared_ptr<model::Class> const &c
		)
		: jclass_type_grammar_t(rns,c)
		, jclass_field_grammar_t::base_type(signature_g)
		{
			signature_g=
				jclass_type_grammar_t::type_g[bind(&jclass_field_grammar_t::on_parse_field_type, this)];
		}
		
		void on_parse_field_type()
		{
			m_field_type=m_create_type;
		}

		jclass_type_grammar_t::create_type_t	m_field_type;
		
		jclass_type_grammar_t::qi_rule_t		signature_g;
	};

} //namespace anonymous


JavaClassScanner::JavaClassScanner(shared_ptr<model::Namespace> const &rns, shared_ptr<model::Class> const &c, shared_ptr<char> const &cd)
: m_RootNS(rns)
, m_Class(c)
, m_ClassData(cd)
{
}

JavaClassScanner::~JavaClassScanner()
{
}

bool JavaClassScanner::scan()
{
	if(shared_ptr<JavaClass> jClass=shared_ptr<JavaClass>(jclass_class_new_from_buffer(m_ClassData.get()), bind(&jclass_class_free, _1)))
	{
		for(uint16_t m=0;m<jClass->methods_count;++m)
		{
			shared_ptr<char> pDescriptor=shared_ptr<char>(jclass_field_get_descriptor(jClass->methods+m, jClass->constant_pool), bind(&free, _1));
			shared_ptr<char> pMethodName=shared_ptr<char>(jclass_field_get_name(jClass->methods+m, jClass->constant_pool), bind(&free, _1));
			if(pDescriptor && pMethodName)
			{
				std::string strDescriptor(pDescriptor.get());

				typedef std::string::const_iterator iterator_type;
				typedef jclass_method_grammar<iterator_type> jclass_method_grammar_type;

				iterator_type iter=strDescriptor.begin();
				iterator_type end=strDescriptor.end();

				jclass_method_grammar_type methodSignatureGrammar(
					m_RootNS,
					m_Class
				);
				
				if(phrase_parse(iter, end, methodSignatureGrammar, ascii::space) && iter == end)
				{
					model::Method::argument_types_t arg_types;
					BOOST_FOREACH( jclass_method_grammar_type::create_type_t createArg, methodSignatureGrammar.m_method_argument_types)
					{
						shared_ptr<model::Type> argType=createArg();
						BOOST_ASSERT(argType);
						if(argType)
							arg_types.push_back(argType);
					}
					

					shared_ptr<model::Type> retType=methodSignatureGrammar.m_method_return_type();
					BOOST_ASSERT(retType);
					if(arg_types.size()==methodSignatureGrammar.m_method_argument_types.size() && retType)
					{
						shared_ptr<model::Method> pNewMethod=m_Class->add_method(std::string(pMethodName.get()));
						BOOST_ASSERT(pNewMethod);
						if(pNewMethod)
						{
							for(std::size_t flag=0;flag<model::ClassMember::kAccessFlagsSize;++flag)
								pNewMethod->set_access_flag(static_cast<model::ClassMember::eAccessFlags>(flag), ((jClass->methods+m)->access_flags & (1<<flag))?true:false);

							pNewMethod->set_return_type(retType);
							pNewMethod->set_argument_types(arg_types);

						}
					}
				}
				else
				{
					std::string parse_err_at(iter,end);

					std::cout << "-------------------------\n";
					std::cout << "Parsing failed\n";
					std::cout << "stopped at: \": " << parse_err_at << "\"\n";
					std::cout << "-------------------------\n";
				}
			}
		}

		for(uint16_t f=0;f<jClass->fields_count;++f)
		{
			shared_ptr<char> pDescriptor=shared_ptr<char>(jclass_field_get_descriptor(jClass->fields+f, jClass->constant_pool), bind(&free, _1));
			shared_ptr<char> pFieldName=shared_ptr<char>(jclass_field_get_name(jClass->fields+f, jClass->constant_pool), bind(&free, _1));
			if(pDescriptor && pFieldName)
			{
				std::string strDescriptor(pDescriptor.get());

				typedef std::string::const_iterator iterator_type;
				typedef jclass_field_grammar<iterator_type> jclass_field_grammar_type;

				iterator_type iter=strDescriptor.begin();
				iterator_type end=strDescriptor.end();

				jclass_field_grammar_type fieldSignatureGrammar(
					m_RootNS,
					m_Class
				);

				if(phrase_parse(iter, end, fieldSignatureGrammar, ascii::space) && iter == end)
				{
					shared_ptr<model::Type> fieldType=fieldSignatureGrammar.m_field_type();
					BOOST_ASSERT(fieldType);
					if(fieldType)
					{
						shared_ptr<model::Field> pNewField=m_Class->add_field(std::string(pFieldName.get()));
						BOOST_ASSERT(pNewField);
						if(pNewField)
						{
							pNewField->set_type(fieldType);
							for(std::size_t flag=0;flag<model::ClassMember::kAccessFlagsSize;++flag)
								pNewField->set_access_flag(static_cast<model::ClassMember::eAccessFlags>(flag), ((jClass->fields+f)->access_flags & (1<<flag))?true:false);
						}
					}
				}
				else
				{
					std::string parse_err_at(iter,end);

					std::cout << "-------------------------\n";
					std::cout << "Parsing failed\n";
					std::cout << "stopped at: \": " << parse_err_at << "\"\n";
					std::cout << "-------------------------\n";
				}
			}
			
		}
		return true;
	}
	return false;
}