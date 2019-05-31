#include "widget.h"
#include <QApplication>
#include "qtpluginmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QtPluginsManager::getInstance().loadAllPlugins();
    QtPluginsManager::getInstance().initSignalAndSlot();
    Widget w;
    w.show();
    return a.exec();
}
