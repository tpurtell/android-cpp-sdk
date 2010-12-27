#ifndef JAVA2CPP_PRECOMPILE_H
#define JAVA2CPP_PRECOMPILE_H

#define BOOST_PROCESS_WINDOWS_USE_NAMED_PIPE
#define BOOST_PARAMETER_MAX_ARITY 10

#include <QWizardPage>
#include <QFileInfo>
#include <QListView>
#include <QTreeView>
#include <QAbstractItemModel>
#include <QAbstractListModel>
#include <QSplitter>
#include <QTabWidget>
#include <QDialog>
#include <QFileDialog>
#include <QMenuBar>
#include <QMenu>
#include <QWizard>
#include <QTextEdit>
#include <QApplication>

#include <boost/config.hpp>
#include <boost/config/warning_disable.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/scoped_ptr.hpp>
#include <boost/smart_ptr/weak_ptr.hpp>
#include <boost/smart_ptr/scoped_array.hpp>
#include <boost/smart_ptr/enable_shared_from_this2.hpp>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/mem_fun.hpp>
#include <boost/multi_index/random_access_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/string.hpp>
#include <boost/parameter/keyword.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/find.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/algorithm/string/erase.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <boost/algorithm/string/find_iterator.hpp>
#include <boost/foreach.hpp>
#include <boost/system/system_error.hpp>
#include <boost/format.hpp>
#include <boost/signals2.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/bind.hpp>
#include <boost/dynamic_bitset.hpp>
#include <boost/filesystem.hpp>


#include <stack>

using namespace boost;

#include <jclass/jar.h>
#include <jclass/class.h>
#include <jclass/attributes.h>
#include <jclass/field.h>

#endif //JAVA2CPP_PRECOMPILE_H