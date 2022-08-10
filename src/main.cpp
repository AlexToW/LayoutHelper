#include "mainwindow.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    //const QString path_icon = "C:\\Users\\Alexander\\Documents\\LayoutHelper\\icon1.png";
    const QString path_icon = "icon1.png";
    QIcon icon(path_icon);
    w.setWindowIcon(icon);
    const QString window_title = "LayoutHelper by Salex";
    w.setWindowTitle(window_title);
    w.show();
    return a.exec();
}
