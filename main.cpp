#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto arguments = a.arguments();
    QString dir = QLatin1String("");
    QString classes_names_file = QLatin1String("");
    if (arguments.size() >= 3) {
	dir = arguments[1];
	classes_names_file = arguments[2];
    }
    
    MainWindow w;
    w.show();
    if (!dir.isEmpty() && !classes_names_file.isEmpty()) {
	w.load_image_dir(dir);
	w.load_label_list_data(classes_names_file);
	w.init();
    }
    return a.exec();
}


