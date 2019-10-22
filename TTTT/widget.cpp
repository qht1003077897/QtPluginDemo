#include "widget.h"
#include "ui_widget.h"
#include "qtpluginmanager.h"
#include "interfaceplugin.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButtonA,SIGNAL(clicked()),this,SLOT(clickA()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::clickA()
{
    QPluginLoader *loader =  QtPluginsManager::getInstance()->getPlugin("pluginA");

    if(loader)
    {
        auto obj = loader->instance();
        if(obj->isWidgetType())
        {
            QWidget *widget = qobject_cast<QWidget*>(obj);
            widget->show();
        }
    }
    else
    {
        qDebug() << "未能找到插件A";
    }
}

