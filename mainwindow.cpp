#include "mainwindow.h"

MainWindow::MainWindow()
{
    // Initialization

    main_window     = new QWidget();
    plots_window    = new QWidget();
    settings_window = new QWidget();

    current_system  = new QComboBox();

    main_layout     = new QGridLayout();
    plots_layout    = new QGridLayout();
    settings_layout = new QGridLayout();

    main_view       = new QGraphicsView();
    plots_view_1    = new QGraphicsView();
    plots_view_2    = new QGraphicsView();
    plots_view_3    = new QGraphicsView();

    main_scene      = new QGraphicsScene();
    plot_1_scene    = new QGraphicsScene();
    plot_2_scene    = new QGraphicsScene();
    plot_3_scene    = new QGraphicsScene();

    main_button     = new QPushButton("&start");
    reset_button    = new QPushButton("&reset");

    length_input_label  = new QLabel("Enter lenght              (0.00 - 2.00) m");
    length_input        = new QLineEdit();
    lenght_input_value  = new QLabel();
    mass_input_label    = new QLabel("Enter mass                (0.1 - 100.0) kg");
    mass_input          = new QLineEdit();
    mass_input_value    = new QLabel();
    g_input_label       = new QLabel("Enter g                (0.0 - 100.0) m/s^2");
    g_input             = new QLineEdit();
    g_input_value       = new QLabel();
    k_input_label       = new QLabel("Enter k                     (0.0 - 50.0) N/m");
    k_input             = new QLineEdit();
    k_input_value       = new QLabel();

    dlength_input_label = new QLabel("Enter dl (part of Lenght) (-0.2 - 0.2)");
    dlength_input       = new QLineEdit();
    dlength_input_value = new QLabel();

    attenuation_input_label     = new QLabel("Attenuation           (0.0 - 50.0) kg/s");
    attenuation_input           = new QLineEdit();
    attenuation_input_value     = new QLabel();
    f_1_input_label     = new QLabel("Enter f_1                     (-0.5 - 0.5) rad");
    f_1_input           = new QLineEdit();
    f_1_input_value     = new QLabel();
    f_0_input_label     = new QLabel("Enter f_0                     (-0.5 - 0.5) rad");
    f_0_input           = new QLineEdit();
    f_0_input_value     = new QLabel();


    math_animation              = new QCheckBox("Math animation");
    math_animation_attenuation  = new QCheckBox("Math Attenuation");
    math_animation_label        = new QLabel();
    math_animation_attenuation->setEnabled(false);
    real_animation              = new QCheckBox("Real animation");
    real_animation_attenuation  = new QCheckBox("Real Attenuation");
    real_animation_attenuation->setEnabled(false);
    real_animation_label        = new QLabel();


    timer           = new QTimer();

    // Setting windows

    // =====================================================================    MAIN WINDOW
    main_view->setScene(main_scene);
    main_view->setFixedSize(main_scene_width, main_scene_height);
    main_view->setSceneRect(0, 0, main_scene_width, main_scene_height);
    main_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    main_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    main_layout->addWidget(main_view);

    main_window->setLayout(main_layout);
    main_window->setFixedSize(main_window_width, main_window_height);

    // =====================================================================    PLOTS WINDOW
    plots_view_1->setScene(plot_1_scene);
    plots_view_2->setScene(plot_2_scene);
    plots_view_3->setScene(plot_3_scene);

    plots_view_1->setFixedSize(plots_window_width, plots_window_height/4);
    plots_view_1->setSceneRect(0, 0, plots_window_width, plots_window_height);
    plots_view_1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    plots_view_1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    plots_view_2->setFixedSize(plots_window_width, plots_window_height/4);
    plots_view_2->setSceneRect(0, 0, plots_window_width, plots_window_height);
    plots_view_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    plots_view_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    plots_view_3->setFixedSize(plots_window_width, plots_window_height/2);
    plots_view_3->setSceneRect(0, 0, plots_window_width, plots_window_height);
    plots_view_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    plots_view_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    plots_layout->addWidget(plots_view_1);
    plots_layout->addWidget(plots_view_2);
    plots_layout->addWidget(plots_view_3);

    plots_window->setLayout(plots_layout);
    plots_window->setFixedSize(plots_window_width + 30, plots_window_height + 30);

    // Plots comments


    // =====================================================================    SETTINGS WINDOW
    current_system->addItem("first");
    current_system->addItem("second");
    current_system->addItem("third");

    settings_layout->addWidget(length_input_label,  0, 0);
    settings_layout->addWidget(length_input,        0, 1);
    settings_layout->addWidget(lenght_input_value,  0, 2);
    lenght_input_value->setMinimumWidth(50);
    settings_layout->addWidget(mass_input_label,    1, 0);
    settings_layout->addWidget(mass_input,          1, 1);
    settings_layout->addWidget(mass_input_value,    1, 2);
    mass_input_value->setMinimumWidth(50);
    settings_layout->addWidget(g_input_label,       2, 0);
    settings_layout->addWidget(g_input,             2, 1);
    settings_layout->addWidget(g_input_value,       2, 2);
    g_input_value->setMinimumWidth(50);
    settings_layout->addWidget(k_input_label,       3, 0);
    settings_layout->addWidget(k_input,             3, 1);
    settings_layout->addWidget(k_input_value,       3, 2);
    k_input_value->setMinimumWidth(50);

    k_input->hide();
    k_input_label->hide();
    k_input_value->hide();

    settings_layout->addWidget(dlength_input_label,       4, 0);
    settings_layout->addWidget(dlength_input,             4, 1);
    settings_layout->addWidget(dlength_input_value,       4, 2);
    dlength_input_value->setMinimumWidth(50);

    dlength_input->hide();
    dlength_input_label->hide();
    dlength_input_value->hide();

    settings_layout->addWidget(f_1_input_label,     5, 0);
    settings_layout->addWidget(f_1_input,           5, 1);
    settings_layout->addWidget(f_1_input_value,     5, 2);
    f_1_input_value->setMinimumWidth(50);

    f_1_input->hide();
    f_1_input_label->hide();
    f_1_input_value->hide();

    settings_layout->addWidget(f_0_input_label,     6, 0);
    settings_layout->addWidget(f_0_input,           6, 1);
    settings_layout->addWidget(f_0_input_value,     6, 2);
    f_0_input_value->setMinimumWidth(50);
    settings_layout->addWidget(math_animation,              7, 0);
    settings_layout->addWidget(math_animation_label,        7, 1);
    settings_layout->addWidget(real_animation,              8, 0);
    settings_layout->addWidget(real_animation_label,        8, 1);

    settings_layout->addWidget(attenuation_input_label,     9, 0);
    settings_layout->addWidget(attenuation_input,           9, 1);
    settings_layout->addWidget(attenuation_input_value,     9, 2);

    settings_layout->addWidget(main_button,        10, 0, Qt::AlignBottom);
    settings_layout->addWidget(reset_button,       10, 1, Qt::AlignBottom);
    settings_layout->addWidget(current_system,     11, 0);

    settings_window->setLayout(settings_layout);
    settings_window->resize(settings_window_width, settings_window_height);

    // Setting connections

    connect(timer,          SIGNAL(timeout()),                  this, SLOT(NextFrame()));

    connect(main_button,    SIGNAL(released()),                 this, SLOT(ChangeAnimationStatus()));
    connect(reset_button,   SIGNAL(released()),                 this, SLOT(Reset()));
    connect(current_system, SIGNAL(currentIndexChanged(int)),   this, SLOT(ChangeCurrentAnimation(int)));

    timer->start(frame_frequency);

    // Show windows

    main_window->       move(100 + settings_window_width + 35, 100);
    plots_window->      move(100, 100);
    settings_window->   move(50  + settings_window_width + main_window_width, 200);

    plots_window->      show();
    main_window->       show();
    settings_window->   show();
}

MainWindow::~MainWindow()
{

}

void MainWindow::NextFrame()
{
    L = length_input->text().toDouble();
    if(L > max_L)               L = max_L;
    if(L <= min_L)              L = 1;
    lenght_input_value->setText(QString::number(L));

    m = mass_input->text().toDouble();
    if(m > max_m)               m = max_m;
    if(m <= min_m)              m = 1;
    mass_input_value->setText(QString::number(m));

    g = g_input->text().toDouble();
    if(g > max_g)               g = max_g;
    if(g <= min_g)              g = 9.8;
    g_input_value->setText(QString::number(g));

    k = k_input->text().toDouble();
    if(k > max_k)               k = max_k;
    if(k < min_k)               k = min_k;
    k_input_value->setText(QString::number(k));

    dL = dlength_input->text().toDouble();
    if(dL > max_dL)             dL = max_dL;
    if(dL < min_dL)             dL = min_dL;
    dlength_input_value->setText(QString::number(dL));

    d = attenuation_input->text().toDouble();
    if(d > max_d)               d = max_d;
    if(d <= min_d)              d = min_d;
    attenuation_input_value->setText(QString::number(d));

    f_0 = f_0_input->text().toDouble();
    if(f_0 > max_f_0)           f_0 = max_f_0;
    if(f_0 <= min_f_0)          f_0 = min_f_0;
    f_0_input_value->setText(QString::number(f_0));

    f_1 = f_1_input->text().toDouble();
    if(f_1 > max_f_0)           f_1 = max_f_0;
    if(f_1 < min_f_0)           f_1 = min_f_0;
    f_1_input_value->setText(QString::number(f_1));

    if(show_animation)
    {
        main_scene->clear();

        double t  = T/1000;
        double dt = dT/1000;

        T += dT;

        L *= 100;
        g *= 100;

        switch (current_animation)
        {
            case 0:
            {
                x_0_1    = main_scene_width/2;
                y_0_1    = main_scene_height/4;

                double v = 0;

                // =================================    MATH
                if(math_animation->isChecked())
                {
                    if(d/m/2 > sqrt(g/L))
                    {
                        double a_1 = ((-1)*d/2/m + sqrt((d/2/m)*(d/2/m) - g/L));
                        double a_2 = ((-1)*d/2/m - sqrt((d/2/m)*(d/2/m) - g/L));

                        double x_1 = f_0*a_2/(a_1 - a_2)*(-1);
                        double x_2 = f_0*a_1/(a_1 - a_2);

                        f_1 = x_1*exp(a_1*t) + x_2*exp(a_2*t);

                        v = (x_1*a_1*exp(a_2*t) + x_2*a_2*exp(a_1*t))*L;
                    }
                    else
                    {
                        math_animation_label->setText("");
                        w_1 = sqrt(g/L - d*d/m*m/4);

                        double gamma = atan(w_1*2*m/d);
                        double A     = f_0/sin(gamma);

                        f_1 = A*exp((-1)*d/2/m*t)*sin(w_1*t + gamma);

                        v = (A*exp((-1)*d/2/m*t)*((-1)*d/2/m*sin(w_1*t + gamma) + w_1*cos(w_1*t + gamma)))*L;
                    }

                    main_scene->addEllipse(x_0_1 + L*sin(f_1) - R, y_0_1 + L*cos(f_1) - R, 2*R, 2*R, QPen(), QBrush(Qt::red));
                    main_scene->addLine(x_0_1, y_0_1, x_0_1 + L*sin(f_1), y_0_1 + L*cos(f_1));

                    DrawPlots(f_1, v, Qt::red);
                }

                // =================================    REAL

                if(real_animation->isChecked())
                {
                    if(!parameters_set)
                    {
                        x_1 = x_0_1 + L*sin(f_0);
                        y_1 = y_0_1 + L*cos(f_0);
                        v_x_1 = 0;
                        parameters_set = true;
                    }

                    double v = v_x_1*L/(y_1 - y_0_1);
                    v_x_1 -= ((g*(y_1 - y_0_1)/L + v*v/L)*(x_1 - x_0_1)/L + d*v*(y_1 - y_0_1)/L)*dt;    // (g*cos + v^2/L)*sin


                    x_1 += v_x_1*dt;
                    y_1  = y_0_1 + sqrt(L*L - (x_1 - x_0_1)*(x_1 - x_0_1));

                    main_scene->addEllipse(x_1 - R, y_1 - R, 2*R, 2*R, QPen(), QBrush(Qt::green));
                    main_scene->addLine(x_0_1, y_0_1, x_1, y_1);

                    DrawPlots((x_1 - x_0_1)/L, v, Qt::green);
                }

                break;
            }
            case 1:
            {
                x_0_1 = main_scene_width/4;
                x_0_2 = main_scene_width/4*3;
                y_0_1 = main_scene_height/4;
                y_0_2 = main_scene_height/4;

                // =================================    MATH

                if(math_animation->isChecked())
                {
                    double f_0_1 = 0;
                    double f_0_2 = 0;
                    double f_2   = 0;
                    double f_3   = 0;
                    double v = 0;
                    if(d != 0)
                    {
                        math_animation_label->setText("Attenuation too big");
                    }
                    else if(f_1 != 0)
                    {
                        math_animation_label->setText("f_1 can be only 0");
                    }
                    else
                    {
                        math_animation_label->setText("");
                        f_0_1 = f_1;
                        f_0_2 = f_0;

                        w_1 = sqrt(g/L);
                        w_2 = sqrt(g/L + 2*k/m);

                        double A = f_0_1 + f_0_2;
                        double B = f_0_1 - f_0_2;

                        f_2 = A*cos(w_1*t)/2 + B*cos(w_2*t)/2;
                        f_3 = A*cos(w_1*t)/2 - B*cos(w_2*t)/2;

                        v = ((-1)*A*w_1*sin(w_1*t)/2 + B*w_2*sin(w_2*t))*L/1.5;
                    }

                    main_scene->addEllipse(x_0_1 + L*sin(f_2) - 10, y_0_1 + L*cos(f_2) - 10, 20, 20, QPen(), QBrush(Qt::red));
                    main_scene->addLine(x_0_1, y_0_1, x_0_1 + L*sin(f_2), y_0_1 + L*cos(f_2));
                    main_scene->addEllipse(x_0_2 + L*sin(f_3) - 10, y_0_2 + L*cos(f_3) - 10, 20, 20, QPen(), QBrush(Qt::red));
                    main_scene->addLine(x_0_2, y_0_2, x_0_2 + L*sin(f_3), y_0_2 + L*cos(f_3));
                    main_scene->addLine(x_0_1 + L*sin(f_2), y_0_1 + L*cos(f_2), x_0_2 + L*sin(f_3), y_0_2 + L*cos(f_3));

                    DrawPlots(f_3, v, Qt::red);
                }

                // =================================    REAL

                if(real_animation->isChecked())
                {
                    if(!parameters_set)
                    {
                        w_3   = 0;
                        w_4   = 0;
                        f_1_1 = f_1;
                        f_1_2 = f_0;
                        parameters_set = true;
                    }

                    double c = atan((cos(f_1_1) - cos(f_1_2)) / (1 + sin(f_1_2) - sin(f_1_1)));

                    w_3 -= (g/L*sin(f_1_1) - k/m*(sin(f_1_2) - sin(f_1_1))*cos(f_1_1 - c) + w_3*d)*dt;
                    w_4 -= (g/L*sin(f_1_2) + k/m*(sin(f_1_2) - sin(f_1_1))*cos(f_1_2 - c) + w_4*d)*dt;

                    f_1_1 += w_3*dt;
                    f_1_2 += w_4*dt;

                    main_scene->addEllipse(x_0_1 + L*sin(f_1_1) - 10, y_0_1 + L*cos(f_1_1) - 10, 20, 20, QPen(), QBrush(Qt::green));
                    main_scene->addLine(x_0_1, y_0_1, x_0_1 + L*sin(f_1_1), y_0_1 + L*cos(f_1_1));
                    main_scene->addEllipse(x_0_2 + L*sin(f_1_2) - 10, y_0_2 + L*cos(f_1_2) - 10, 20, 20, QPen(), QBrush(Qt::green));
                    main_scene->addLine(x_0_2, y_0_2, x_0_2 + L*sin(f_1_2), y_0_2 + L*cos(f_1_2));
                    main_scene->addLine(x_0_1 + L*sin(f_1_1), y_0_1 + L*cos(f_1_1), x_0_2 + L*sin(f_1_2), y_0_2 + L*cos(f_1_2));

                    DrawPlots(f_1_2, w_4*L, Qt::green);
                }

                break;
            }
            case 2:
            {
                x_0_1    = main_scene_width/2;
                y_0_1    = main_scene_height/4;

                if(!parameters_set)
                {
                    x_1 = x_0_1 + (L*(1 + dL))*sin(f_0);
                    y_1 = y_0_1 + (L*(1 + dL))*cos(f_0);
                    v_x_1 = 0;
                    v_y_1 = 0;
                    parameters_set = true;
                }

                x_1 += v_x_1*dt;
                y_1 += v_y_1*dt;

                double L_1 = sqrt((x_1 - x_0_1)*(x_1 - x_0_1) + (y_1 - y_0_1)*(y_1 - y_0_1));

                v_x_1 -= k/m*(L_1 - L)*(x_1 - x_0_1)/L_1*dt + v_x_1*d/100;          // v_x_1 has value in pixels
                v_y_1 += (g - k/m*(L_1 - L)*(y_1 - y_0_1)/L_1)*dt - v_y_1*d/100;    // v_y_1 has value in pixels

                main_scene->addEllipse(x_1 - 10, y_1 - 10, 20, 20, QPen(), QBrush(Qt::green));
                main_scene->addLine(x_0_1, y_0_1, x_1, y_1);

                double f = atan((x_1 - x_0_1)/(y_1 - y_0_1));

                DrawPlots(f, v_x_1*cos(f) + v_y_1*sin(f), Qt::green);

                break;
            }
        }
    }
}

void MainWindow::ChangeAnimationStatus()
{
    show_animation = !show_animation;

    if(show_animation)  main_button->setText("&stop");
    else                main_button->setText("&start");
}

void MainWindow::ChangeCurrentAnimation(int new_animation_number)
{
    show_animation = false;
    main_button->setText("&start");

    current_animation = new_animation_number;
    /* */if(current_animation == 0)
    {
        k_input->hide();
        k_input_label->hide();
        k_input_value->hide();
        dlength_input->hide();
        dlength_input_label->hide();
        dlength_input_value->hide();
        f_1_input->hide();
        f_1_input_label->hide();
        f_1_input_value->hide();

        math_animation->show();
        real_animation->show();
    }
    else if(current_animation == 1)
    {
        k_input->show();
        k_input_label->show();
        k_input_value->show();
        dlength_input->hide();
        dlength_input_label->hide();
        dlength_input_value->hide();
        f_1_input->show();
        f_1_input_label->show();
        f_1_input_value->show();

        math_animation->show();
        real_animation->show();
    }
    else
    {
        k_input->show();
        k_input_label->show();
        k_input_value->show();
        dlength_input->show();
        dlength_input_label->show();
        dlength_input_value->show();
        f_1_input->hide();
        f_1_input_label->hide();
        f_1_input_value->hide();

        math_animation->hide();
        real_animation->hide();
    }
}

void MainWindow::Reset()
{
    T = 0;

    main_scene->clear();
    plot_1_scene->clear();
    plot_2_scene->clear();
    plot_3_scene->clear();

    parameters_set = false;
    plots_clean    = true;
}

void MainWindow::DrawPlots(double x, double v, QColor color)
{
    if(plots_clean)     // Drawing axis
    {
        plot_1_scene->addLine(10, plots_window_height/8, B, plots_window_height/8);
        plot_1_scene->addLine(10, plots_window_height/8 - A_1, 10, plots_window_height/8 + A_1);
        plot_2_scene->addLine(10, plots_window_height/8, B, plots_window_height/8);
        plot_2_scene->addLine(10, plots_window_height/8 - A_1, 10, plots_window_height/8 + A_1);
        plot_3_scene->addLine(10, plots_window_height/4, B, plots_window_height/4);
        plot_3_scene->addLine(plots_window_width/2, plots_window_height/4 - A_2, plots_window_width/2, plots_window_height/4 + A_2);

        for(int i = 0; i < 4; i++)
        {
            plot_1_scene->addEllipse(10 + i*100, plots_window_height/8, 1, 1);
            plot_2_scene->addEllipse(10 + i*100, plots_window_height/8, 1, 1);
        }
        for(int i = -2; i < 3; i++)
        {
            plot_1_scene->addEllipse(10, plots_window_height/8 + i*A_1*0.4, 1, 1);
            plot_2_scene->addEllipse(10, plots_window_height/8 + i*A_1*0.4, 1, 1);
        }
        for(int i = -2; i < 3; i++)
        {
            plot_3_scene->addEllipse(plots_window_width/2 + 80*i, plots_window_height/4, 2, 2, QPen(), QBrush(Qt::black));   // df = 0.4 rad
            plot_3_scene->addEllipse(plots_window_width/2, plots_window_height/4 + i*A_1*0.8, 2, 2, QPen(), QBrush(Qt::black));// dv = 1 m/s
        }


        plot_1_comment  = new QGraphicsTextItem();
        plot_1_comment->setPlainText("f (t)");
        plot_1_comment->setPos(plots_window_width - 50, 5);
        plot_1_legend   = new QGraphicsTextItem();
        plot_1_legend->setPos(plots_window_width - 150, plots_window_height/4 - 30);
        plot_1_legend->setPlainText("df = 0.2 rad, dt = 1 s");
        plot_1_scene->addItem(plot_1_comment);
        plot_1_scene->addItem(plot_1_legend);

        plot_2_comment  = new QGraphicsTextItem();
        plot_2_comment->setPos(plots_window_width - 50, 5);
        plot_2_comment->setPlainText("v (t)");
        plot_2_legend   = new QGraphicsTextItem();
        plot_2_legend->setPos(plots_window_width - 150, plots_window_height/4 - 30);
        plot_2_legend->setPlainText("dv = 1 m/s,  dt = 1 s");
        plot_2_scene->addItem(plot_2_comment);
        plot_2_scene->addItem(plot_2_legend);

        plot_3_comment  = new QGraphicsTextItem();
        plot_3_comment->setPos(plots_window_width - 50, 5);
        plot_3_comment->setPlainText("v (f)");
        plot_3_legend   = new QGraphicsTextItem();
        plot_3_legend->setPos(plots_window_width - 150, plots_window_height/2 - 30);
        plot_3_legend->setPlainText("df = 0.4 rad, dv = 1 m/s");
        plot_3_scene->addItem(plot_3_comment);
        plot_3_scene->addItem(plot_3_legend);

        plots_clean = false;
    }


    plots_t = (int)T/10 % B;

    plot_1_scene->addEllipse(10 + plots_t, plots_window_height/8 - A_1*(x/max_f_0), 1, 1, QPen(color), QBrush(color));
    plot_2_scene->addEllipse(10 + plots_t, plots_window_height/8 - A_1*(v/v_max),   1, 1, QPen(color), QBrush(color));
    if(plots_t > B - 20)
    {
        plot_1_scene->clear();
        plot_2_scene->clear();

        plot_1_scene->addLine(10, plots_window_height/8, B, plots_window_height/8);
        plot_1_scene->addLine(10, plots_window_height/8 - A_1, 10, plots_window_height/8 + A_1);
        plot_2_scene->addLine(10, plots_window_height/8, B, plots_window_height/8);
        plot_2_scene->addLine(10, plots_window_height/8 - A_1, 10, plots_window_height/8 + A_1);

        for(int i = 0; i < 4; i++)
        {
            plot_1_scene->addEllipse(10 + i*100, plots_window_height/8, 1, 1);      // dt = 1 s
            plot_2_scene->addEllipse(10 + i*100, plots_window_height/8, 1, 1);
        }
        for(int i = -2; i < 3; i++)
        {
            plot_1_scene->addEllipse(10, plots_window_height/8 + i*A_1*0.4, 1, 1);  // df = 0.2 rad
            plot_2_scene->addEllipse(10, plots_window_height/8 + i*A_1*0.4, 1, 1);  // dv = 1 m/s
        }

        plot_1_comment  = new QGraphicsTextItem();
        plot_1_comment->setPos(plots_window_width - 50, 5);
        plot_1_comment->setPlainText("f (t)");
        plot_1_legend   = new QGraphicsTextItem();
        plot_1_legend->setPos(plots_window_width - 150, plots_window_height/4 - 30);
        plot_1_legend->setPlainText("df = 0.2 rad, dt = 1 s");
        plot_1_scene->addItem(plot_1_comment);
        plot_1_scene->addItem(plot_1_legend);

        plot_2_comment  = new QGraphicsTextItem();
        plot_2_comment->setPos(plots_window_width - 50, 5);
        plot_2_comment->setPlainText("v (t)");
        plot_2_legend   = new QGraphicsTextItem();
        plot_2_legend->setPos(plots_window_width - 150, plots_window_height/4 - 30);
        plot_2_legend->setPlainText("dv = 1 m/s,  dt = 1 s");
        plot_2_scene->addItem(plot_2_comment);
        plot_2_scene->addItem(plot_2_legend);
    }


    plot_3_scene->addEllipse(plots_window_width/2 + 100*(x/max_f_0), plots_window_height/4 - 2*A_1*(v/v_max),
                             1, 1, QPen(color), QBrush(color));

}
