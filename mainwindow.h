#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <cmath>

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QGraphicsView>
#include <QGraphicsTextItem>
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
    QGraphicsScene  * plot_3_scene;

    QGraphicsView   * main_view;
    QGraphicsView   * plots_view_1;
    QGraphicsView   * plots_view_2;
    QGraphicsView   * plots_view_3;

    QGraphicsTextItem   * plot_1_comment;
    QGraphicsTextItem   * plot_2_comment;
    QGraphicsTextItem   * plot_3_comment;
    QGraphicsTextItem   * plot_1_legend;
    QGraphicsTextItem   * plot_2_legend;
    QGraphicsTextItem   * plot_3_legend;

    QPushButton     * main_button;
    QPushButton     * reset_button;

    QLabel          * lenght_input_value;
    QLabel          * length_input_label;
    QLineEdit       * length_input;
    QLabel          * dlength_input_value;
    QLabel          * dlength_input_label;
    QLineEdit       * dlength_input;
    QLabel          * mass_input_label;
    QLabel          * mass_input_value;
    QLineEdit       * mass_input;
    QLabel          * g_input_label;
    QLabel          * g_input_value;
    QLineEdit       * g_input;
    QLabel          * k_input_label;
    QLabel          * k_input_value;
    QLineEdit       * k_input;
    QLabel          * f_1_input_label;
    QLabel          * f_1_input_value;
    QLineEdit       * f_1_input;
    QLabel          * f_0_input_label;
    QLabel          * f_0_input_value;
    QLineEdit       * f_0_input;
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
    int settings_window_height  = 400;
    int settings_window_width   = 400;

    int  current_animation      = 0;
    bool show_animation         = false;
    int  frame_frequency        = 30;
    bool parameters_set         = false;
    bool plots_clean            = true;

    int A_1                     = 40;
    int A_2                     = 90;
    int B                       = plots_window_width - 10;

    double v_max                = 250;
    double x_max                = 200;

    int plots_t                 = B;
    int t_scale                 = 10;

    // =========================================================    PHYSICS
    double dT       = frame_frequency;
    double T        = 0;

    double min_L    = 0;
    double max_L    = 2;
    double min_dL   = -0.5;
    double max_dL   =  0.5;
    double min_m    = 0;
    double max_m    = 100;
    double min_g    = 1;
    double max_g    = 100;
    double min_d    = 0;
    double max_d    = 50;
    double min_k    = 0;
    double max_k    = 50;
    double min_f_0  = -0.5;
    double max_f_0  =  0.5;

    double L        = min_L;
    double dL       = 0;
    double m        = min_m;
    double g        = 9.8;
    double k        = min_k;
    double d        = 0;
    double f_1      = max_f_0;
    double f_0      = max_f_0;
    double x_0_1    = main_scene_width/2;
    double y_0_1    = main_scene_height/4;
    double x_0_2    = main_scene_width/2;
    double y_0_2    = main_scene_height/4;

    double x_1      = 0;
    double y_1      = 0;
    double x_2      = 0;
    double y_2      = 0;
    double v_x_1    = 0;
    double v_x_2    = 0;
    double v_y_1    = 0;
    double v_y_2    = 0;
    double w_1      = 0;
    double w_2      = 0;
    double w_3      = 0;
    double w_4      = 0;

    double f_1_1    = 0;
    double f_1_2    = 0;

    double R        = 10;

    void DrawPlots(double x, double v, QColor color);

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
