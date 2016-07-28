#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>
#include<QImage>
#include<QLabel>
#include<QMenu>
#include<QMenuBar>
#include<QAction>
#include<QComboBox>
#include<QSpinBox>
#include<QToolBar>
#include<QFontComboBox>
#include<QToolButton>
#include<QTextCharFormat>
#include<showwidget.h>

namespace Ui {
class Editor;
}

class Editor : public QMainWindow
{
    Q_OBJECT

public:
    explicit Editor(QWidget *parent = 0);
    ~Editor();
    void createActions();
    void createMenus();
    void createToolBars();
    void loadFile(QString filename);
    void mergeFormat(QTextCharFormat);

private:
    Ui::Editor *ui;
    QMenu *fileMenu;
    QMenu *zoomMenu;
    QMenu *rotateMenu;
    QMenu *mirrorMenu;
    QImage img;
    QString filename;
    ShowWidget *showWidget;
    QAction *openFileAction;
    QAction *NewFileAction;
    QAction *PrintTextAction;
    QAction *PrintImageAction;
    QAction *exitAction;
    QAction *copyAction;
    QAction *cutAction;
    QAction *pasteAction;
    QAction *aboutAction;
    QAction *zoomInAction;
    QAction *zoomOutAction;
    QAction *rotate90Action;
    QAction *rotate180Action;
    QAction *rotate270Action;
    QAction *mirrorVerticalAction;
    QAction *mirrorHorizontalAction;
    QAction *undoAction;
    QAction *redoAction;
    QToolBar *fileTool;
    QToolBar *zoomTool;
    QToolBar *rotateTool;
    QToolBar *mirrorTool;
    QToolBar *doToolBar;
};

#endif // EDITOR_H
