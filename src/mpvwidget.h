#ifndef PLAYERWINDOW_H
#define PLAYERWINDOW_H

#include <QtWidgets/QOpenGLWidget>
#include <mpv/client.h>
#include <mpv/render_gl.h>

#include "qthelper.hpp"
class MpvWidget Q_DECL_FINAL : public QOpenGLWidget
{
    Q_OBJECT
public:
    MpvWidget(QWidget* parent = 0, Qt::WindowFlags f = 0);
    ~MpvWidget();
    void command(const QVariant& params);
    void setProperty(const QString& name, const QVariant& value);
    QVariant getProperty(const QString& name) const;
    QSize sizeHint() const { return QSize(1920, 1080); }
Q_SIGNALS:
    void durationChanged(int value);
    void positionChanged(double value);
    void positionChanged(int value);
    void speedChanged(double value);
    void frameChanged(int value);
    void newFileLoaded(QList<int>);
protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
private Q_SLOTS:
    void on_mpv_events();
    void maybeUpdate();
private:

    void handle_mpv_event(mpv_event* event);
    static void on_update(void* ctx);

    mpv_handle* mpv;
    mpv_render_context* mpv_gl;
};



#endif // PLAYERWINDOW_H