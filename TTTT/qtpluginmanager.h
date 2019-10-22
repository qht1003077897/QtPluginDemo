#pragma once

#include <QObject>
#include <QPluginLoader>
#include <QVariant>
#include "qtpluginsmanagerprivate.h"
#include "pluginMetaData.h"
#include <QDir>

class  QtPluginsManager : public QObject
{
    Q_OBJECT

public:
    static QtPluginsManager *getInstance()
    {
        if(m_instance == Q_NULLPTR) {
            m_instance = new QtPluginsManager();
        }

        return m_instance;
    }

public:
    QDir getPluginPath();
    //加载所有插件
    void loadAllPlugins();
    //扫描JSON文件中的插件元数据
    void scan(const QString &filepath);
    //加载其中某个插件
    void loadPlugin(const QString &filepath);
    //卸载所有插件
    void unloadAllPlugins();
    //卸载某个插件
    void unloadPlugin(const QString &filepath);
    //获取所有插件
    QList<QPluginLoader *> allPlugins();
    //获取某个插件
    QPluginLoader* getPlugin(const QString &name);
    //初始化和插件通信的信号槽
    void initSignalAndSlot();

public slots:
    //接受来自各插件的消息
    void recMsgfromPlugin(PluginMetaData);

private:
    QtPluginsManager()
    {
        d = new QtPluginsManagerPrivate;
    }

    QtPluginsManagerPrivate *d;
    static QtPluginsManager *m_instance;
};

