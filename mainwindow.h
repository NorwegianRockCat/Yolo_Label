#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWheelEvent>
#include <QTableWidgetItem>
#include <QMessageBox>

#include <iostream>
#include <fstream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool load_image_dir(const QString &dir);
    void load_label_list_data(const QString &);
    void init();

private slots:
    void on_pushButton_open_files_clicked();
    void on_pushButton_change_dir_clicked();
    void on_pushButton_save_clicked();
    void on_pushButton_remove_clicked();

    void on_pushButton_prev_clicked();
    void on_pushButton_next_clicked();

    void keyPressEvent(QKeyEvent *);

    void next_img(bool bSavePrev = true);
    void prev_img(bool bSavePrev = true);
    void save_label_data() const;
    void clear_label_data();

    void next_label();
    void prev_label();

    void on_tableWidget_label_cellDoubleClicked(int , int );
    void on_tableWidget_label_cellClicked(int , int );

    void on_horizontalSlider_images_sliderMoved(int );



private:
    void            init_table_widget();
    void            init_button_event();
    void            init_horizontal_slider();

    void            img_open(const int);
    void            set_label_progress(const int);
    void            set_focused_file(const int);

    void            goto_img(const int);

    QString         get_labeling_data(const QString &)const;

    void            set_label(const int);
    void            set_label_color(const int , const QColor);

    void            pjreddie_style_msgBox(QMessageBox::Icon, QString, QString);

    void            open_img_dir(bool&);
    void            open_obj_file(bool&);

    void            reupdate_img_list();

    Ui::MainWindow *ui;

    QString         m_imgDir;
    QStringList     m_imgList;
    int             m_imgIndex;

    QStringList     m_objList;
    int             m_objIndex;

protected:
    void    wheelEvent(QWheelEvent *);
};

#endif // MAINWINDOW_H
