#include "Precompile.h"
#include "Java2Cpp.h"
#include "JarScanner.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Java2Cpp w;
	w.show();
	return a.exec();
}
