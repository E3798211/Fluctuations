#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <cmath>

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QGraphicsView>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>
#include <QComboBox>
#include <QRadioButton>
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QBrush>
#include <QDebug>
#include <QString>

class MainWindow : public QObject
{
    Q_OBJECT
private:

    // =========================================================    SERVICE
    QWidget         * main_window;
    QWidget         * plots_window;
    QWidget         * settings_window;

    QComboBox       * current_system;

    QGridLayout     * main_layout;
    QGridLayout     * plots_layout;
    QGridLayout     * settings_layout;

    QGraphicsScene  * main_scene;
    QGraphicsScene  * plot_1_scene;
    QGraphicsScene  * plot_2_scene;

    QGraphicsView   * main_view;
    QGraphicsView   * plots_view_1;
    QGraphicsView   * plots_view_2;

    QPushButton     * main_button;
    QPushButton     * reset_button;

    QLabel          * lenght_input_value;
    QLabel          * length_input_label;
    QLineEdit       * length_input;
    QLabel          * mass_input_label;
    QLabel          * mass_input_value;
    QLineEdit       * mass_input;
    QLabel          * g_input_label;
    QLabel          * g_input_value;
    QLineEdit       * g_input;
    QLabel          * attenuation_input_label;
    QLabel          * attenuation_input_value;
    QLineEdit       * attenuation_input;

    QCheckBox       * math_animation;
    QCheckBox       * math_animation_attenuation;
    QLabel          * math_animation_label;
    QCheckBox       * real_animation;
    QCheckBox       * real_animation_attenuation;
    QLabel          * real_animation_label;

    QTimer          * timer;

    int main_window_height      = 430;
    int main_window_width       = 430;
    int main_scene_height       = 400;
    int main_scene_width        = 400;
    int plots_window_height     = 400;
    int plots_window_width      = 400;
    int settings_window_height  = 200;
    int settings_window_width   = 400;

    int  current_animation      = 0;
    bool show_animation         = false;
    int  frame_frequency        = 30;
    bool parameters_set         = false;

    // =========================================================    PHYSICS
    double dT       = frame_frequency;
    double T        = 0;

    double max_L    = 10;
    double min_L    = 1;
    double max_m    = 10;
    double min_m    = 1;
    double max_k    = 10;
    double min_k    = 1;
    double min_f_0  = 0;
    double max_f_0  = 0.5;

    double L        = min_L;
    double m        = min_m;
    double g        = 9.8;
    double k        = min_k;
    double d        = 0;
    double f_0      = max_f_0;
    double x_0_1    = main_scene_width/2;
    double y_0_1    = main_scene_height/4;

    double x_1      = 0;
    double y_1      = 0;
    double v_x_1    = 0;
    double v_x_2    = 0;
    double v_y_1    = 0;
    double v_y_2    = 0;
    double w_1      = 0;
    double w_2      = 0;

    double R        = 10;

    // FIRST
/*
    double L        = 200;
    double m        = 1;
    double g        = 9.8;
    double f_0      = 0.5;

    int x_0         = max_window_width /2;
    int y_0         = max_window_height/4;

    long double x        = x_0 + L*sin(f_0);
    long double y        = 0;//y_0 + sqrt(L*L - (x - x_0)*(x - x_0));
    long double v_x      = 0;
    long double v_y      = 0;
*/
    // SECOND
/*
    double L        = 200;
    double g        = 9.8;
    double k_m      = 0.001;
    //double f_0      = 0.4;

    double f_0_1    = 0;
    double f_0_2    = 0.3;

    double x_0_1    = max_window_width /4;
    double x_0_2    = max_window_width /4 * 3;

    double y_0_1    = max_window_height/4;
    double y_0_2    = max_window_height/4;

    double w_1      = sqrt(g/L);
    double w_2      = sqrt(g/L - 2*k_m);

    double f_1_1    = f_0_1;
    double f_1_2    = f_0_2;

    double w_1_1    = 0;
    double w_1_2    = 0;
*/
    // THIRD
/*
    double L_0      = 130;
    double g        = 98;
    double k        = 5;
    double m        = 1;

    double x_0      = main_window_width /2;  // 200
    double y_0      = main_window_height/5;  // 80

    double x        = 250;
    double y        = 200;

    double v_x      = 0;
    double v_y      = 0;


    double L_0_1    = L_0;
    double g_1      = g;
    double k_1      = k;
    double m_1      = m;

    double x_1      = x;
    double y_1      = y;

    double v_x_1    = 0;
    double v_y_1    = 0;

    double p        = 0.005;
*/
public:
    MainWindow();
    ~MainWindow();

private slots:
    void NextFrame();
    void ChangeAnimationStatus();
    void ChangeCurrentAnimation(int);
    void Reset();
};

#endif // MAINWINDOW_H
