#include "Precompile.h"
#include "Java2Cpp.h"
#include "JarScanner.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.addLibraryPath(a.applicationDirPath() + QLatin1String("/qtplugins"));
	Java2Cpp w;
	w.show();
	return a.exec();
}
