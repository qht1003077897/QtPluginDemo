#include "widget.h"
#include <QApplication>
#include "qtpluginmanager.h"

QtPluginsManager *QtPluginsManager::m_instance = Q_NULLPTR;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QtPluginsManager *pluginsManager = QtPluginsManager::getInstance();

    pluginsManager->loadAllPlugins();
    pluginsManager->initSignalAndSlot();

    Widget w;
    w.show();
    return a.exec();
}
