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

    main_scene      = new QGraphicsScene();
    plot_1_scene    = new QGraphicsScene();
    plot_2_scene    = new QGraphicsScene();

    main_button     = new QPushButton("&start");

    length_input_label  = new QLabel("Enter lenght (1-10)m");
    length_input    = new QLineEdit();
    lenght_input_value  = new QLabel();
    mass_input_label    = new QLabel("Enter mass (0.1 - 10)kg");
    mass_input      = new QLineEdit();
    mass_input_value    = new QLabel("heh");

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

    plots_view_1->setFixedSize(plots_window_width, plots_window_height/2);
    plots_view_1->setSceneRect(0, 0, plots_window_width, plots_window_height);
    plots_view_1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    plots_view_1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    plots_view_2->setFixedSize(plots_window_width, plots_window_height/2);
    plots_view_2->setSceneRect(0, 0, plots_window_width, plots_window_height);
    plots_view_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    plots_view_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    plots_layout->addWidget(plots_view_1);
    plots_layout->addWidget(plots_view_2);

    plots_window->setLayout(plots_layout);
    //plots_window->resize(plots_window_width, plots_window_height);
    plots_window->setFixedSize(plots_window_width, plots_window_height);

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

    settings_layout->addWidget(main_button,         2, 0, Qt::AlignBottom);
    settings_layout->addWidget(current_system,      3, 0);

    settings_window->setLayout(settings_layout);
    settings_window->resize(settings_window_width, settings_window_height);

    // Setting connections

    connect(timer,          SIGNAL(timeout()),                  this, SLOT(NextFrame()));
    connect(main_button,    SIGNAL(released()),                 this, SLOT(ChangeAnimationStatus()));
    connect(current_system, SIGNAL(currentIndexChanged(int)),   this, SLOT(ChangeCurrentAnimation(int)));

    timer->start(frame_frequency);

    // Show windows

    main_window->show();
    //plots_window->show();
    settings_window->show();
}

MainWindow::~MainWindow()
{

}

void MainWindow::NextFrame()
{
    // FIRST
/*
    scene->clear();

    t += dt;

    double w = sqrt(g/L);
    double A_x = L*sin(f_0)*sin(w*t + 3.14/2);
    double A_y = sqrt(L*L - A_x*A_x);

    scene->addEllipse(x_0 + A_x - 10, y_0 + A_y - 10, 20, 20, QPen(), QBrush(Qt::red));
    scene->addLine(x_0, y_0, x_0 + A_x, y_0 + A_y);

    // =================================================

    long double v = sqrt(v_x*v_x + v_y*v_y);

    v_x -= (g*(y - y_0)/L + v*v/L)*(x - x_0)/L*dt;

    x += v_x * dt;
    y = y_0 + sqrt(L*L - (x - x_0)*(x - x_0));

    scene->addEllipse(x - 10, y - 10, 20, 20, QPen(), QBrush(Qt::green));
    scene->addLine(x_0, y_0, x, y);
*/
    // SECOND
/*
    scene->clear();

    dt = 0.4;
    t += dt;

    double A = f_0_1 + f_0_2;
    double B = f_0_1 - f_0_2;

    double f_1 = A*cos(w_1*t)/2 + B*cos(w_2*t)/2;
    double f_2 = A*cos(w_1*t)/2 - B*cos(w_2*t)/2;

    //qDebug() << "f_1 = " << f_1 << "\n" << "f_2 = " << f_2 << "\n";


    scene->addEllipse(x_0_1 + L*sin(f_1) - 10, y_0_1 + L*cos(f_1) - 10, 20, 20, QPen(), QBrush(Qt::red));
    scene->addLine(x_0_1, y_0_1, x_0_1 + L*sin(f_1), y_0_1 + L*cos(f_1));
    scene->addEllipse(x_0_2 + L*sin(f_2) - 10, y_0_2 + L*cos(f_2) - 10, 20, 20, QPen(), QBrush(Qt::red));
    scene->addLine(x_0_2, y_0_2, x_0_2 + L*sin(f_2), y_0_2 + L*cos(f_2));
    scene->addLine(x_0_1 + L*sin(f_1), y_0_1 + L*cos(f_1), x_0_2 + L*sin(f_2), y_0_2 + L*cos(f_2));

    // =================================================

    f_1_1 += w_1_1*dt;
    f_1_2 += w_1_2*dt;

    //qDebug() << "f_1_1 = " << f_1_1 << "\n" << "f_1_2 = " << f_1_2 << "\n\n";

    double c = atan((cos(f_1_1) - cos(f_1_2)) / (1 + sin(f_1_2) - sin(f_1_1)));

    w_1_1 -= (g/L*sin(f_1_1) - k_m*(sin(f_1_2) - sin(f_1_1))*cos(f_1_1 - c))*dt;
    w_1_2 -= (g/L*sin(f_1_2) + k_m*(sin(f_1_2) - sin(f_1_1))*cos(f_1_2 - c))*dt;

    scene->addEllipse(x_0_1 + L*sin(f_1_1) - 10, y_0_1 + L*cos(f_1_1) - 10, 20, 20, QPen(), QBrush(Qt::green));
    scene->addLine(x_0_1, y_0_1, x_0_1 + L*sin(f_1_1), y_0_1 + L*cos(f_1_1));
    scene->addEllipse(x_0_2 + L*sin(f_1_2) - 10, y_0_2 + L*cos(f_1_2) - 10, 20, 20, QPen(), QBrush(Qt::green));
    scene->addLine(x_0_2, y_0_2, x_0_2 + L*sin(f_1_2), y_0_2 + L*cos(f_1_2));
    scene->addLine(x_0_1 + L*sin(f_1_1), y_0_1 + L*cos(f_1_1), x_0_2 + L*sin(f_1_2), y_0_2 + L*cos(f_1_2));
*/
    // THIRD
/*
    main_scene->clear();

    dt = 0.065;

    x += v_x*dt;
    y += v_y*dt;

    double L = sqrt((x - x_0)*(x - x_0) + (y - y_0)*(y - y_0));

    v_x -= k/m*(L - L_0)*(x - x_0)/L*dt;
    v_y += (g - k/m*(L - L_0)*(y - y_0)/L)*dt;

    main_scene->addEllipse(x - 10, y - 10, 20, 20, QPen(), QBrush(Qt::red));
    main_scene->addLine(x_0, y_0, x, y);

    // =================================

    x_1 += v_x_1*dt;
    y_1 += v_y_1*dt;

    double L_1 = sqrt((x_1 - x_0)*(x_1 - x_0) + (y_1 - y_0)*(y_1 - y_0));

    v_x_1 -= k_1/m_1*(L_1 - L_0_1)*(x_1 - x_0)/L_1*dt + v_x_1*p;
    v_y_1 += (g_1 - k_1/m_1*(L_1 - L_0_1)*(y_1 - y_0)/L_1)*dt - v_y_1*p;

    main_scene->addEllipse(x_1 - 10, y_1 - 10, 20, 20, QPen(), QBrush(Qt::green));
    main_scene->addLine(x_0, y_0, x_1, y_1);
*/

    L = length_input->text().toDouble();
    if(L > 1000)        L = 10;
    if(L < 0)           L = 1;

    lenght_input_value->setText(QString::number(L));

    if(show_animation)
    {
        main_scene->clear();
        switch (current_animation)
        {
            case 0:
            {
                T += dt;

                int x_0 = main_scene_width/2;
                int y_0 = main_scene_height/4;

                L *= 100;
                double g = G * 100;

                double t = T/1000;

                // =================================    MATH

                w_1 = sqrt(g/L);
                qDebug() << w_1;
                qDebug() << g;
                qDebug() << L;

                double f_1 = f_0*cos(w_1*t);

                main_scene->addEllipse(x_0 + L*sin(f_1) - R, y_0 + L*cos(f_1) - R, 2*R, 2*R, QPen(), QBrush(Qt::red));
                main_scene->addLine(x_0, y_0, x_0 + L*sin(f_1), y_0 + L*cos(f_1));

                // =================================    REAL

                //

                break;
            }
            case 1:
            {
                //
                break;
            }
            case 2:
            {
                //
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
        length_input->hide();
        length_input_label->hide();
    }
    else if(current_animation == 1)
    {
        length_input->show();
        length_input_label->show();
    }
    else
    {
        //
    }
}






