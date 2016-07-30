#include "editor.h"
#include "ui_editor.h"

Editor::Editor(QWidget *parent) :
    QMainWindow(parent)

{
    setWindowTitle(tr("Easy Word"));
    showWidget = new ShowWidget(this);
    setCentralWidget(showWidget);
    createActions();
    createMenus();
    createToolBars();
    if(img.load("image.png"))
    {
        showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
    }



}

Editor::~Editor()
{

}


void Editor::createActions()
{
    openFileAction = new QAction(QIcon("open.png"),tr("打开"),this);
    openFileAction->setShortcut(tr("Ctrl+O"));
    openFileAction->setStatusTip(tr("打开一个文件"));

    NewFileAction = new QAction(QIcon("new.png"),tr("新建"),this);
    NewFileAction->setShortcut(tr("Ctrl+N"));
    NewFileAction->setStatusTip(tr("新建一个文件"));

    exitAction = new QAction(tr("退出"),this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("退出程序"));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));

    copyAction = new QAction(QIcon("copy.png"),tr("复制"),this);
    copyAction->setShortcut(tr("Ctrl+C"));
    copyAction->setStatusTip(tr("复制文件"));

    cutAction = new QAction(QIcon("cut.png"),tr("剪切"),this);
    cutAction->setShortcut(tr("Ctrl+X"));
    cutAction->setStatusTip(tr("剪切文件"));
    connect(cutAction,SIGNAL(triggered()),showWidget->text,SLOT(cut()));

    pasteAction = new QAction(QIcon("paste.png"),tr("粘贴"),this);
    pasteAction->setShortcut(tr("Ctrl+V"));
    pasteAction->setStatusTip(tr("粘贴文件"));
    connect(pasteAction,SIGNAL(triggered()),showWidget->text,SLOT(paste()));

    aboutAction =new QAction(tr("关于"),this);
    connect(aboutAction,SIGNAL(triggered()),this,SLOT(Qapplication::aboutQt()));

     PrintTextAction = new QAction(QIcon("printText.png"),tr("打印文本"),this);
     PrintTextAction->setStatusTip(tr("打印一个文本"));

     PrintImageAction = new QAction(QIcon("printImage.png"),tr("打印图像"),this);
     PrintImageAction->setStatusTip("打印一幅图像");

     zoomInAction = new QAction(QIcon("zoomin.png"),tr("放大"),this);
     zoomInAction->setStatusTip(tr("放大一张图片"));

     zoomOutAction = new QAction(QIcon("zoomout.png"),tr("缩小"),this);
     zoomOutAction->setStatusTip(tr("放大一张图片"));

     rotate90Action = new QAction(QIcon("rotate90.png"),tr("旋转90°"),this);
     rotate90Action->setStatusTip(tr("将一幅图旋转90°"));

     rotate180Action = new QAction(QIcon("rotate180.png"),tr("旋转180°"),this);
     rotate180Action->setStatusTip(tr("将一幅图旋转180°"));

     rotate270Action = new QAction(QIcon("rotate270.png"),tr("旋转270°"),this);
     rotate270Action->setStatusTip(tr("将一幅图旋转270°"));

     mirrorVerticalAction = new QAction(QIcon("mirrorVertical.png"),tr("纵向镜像"),this);
     mirrorVerticalAction->setStatusTip(tr("对一幅图做纵向镜像"));

     mirrorHorizontalAction = new QAction(QIcon("mirrorHorizontal.png"),tr("横向镜像"),this);
     mirrorHorizontalAction->setStatusTip(tr("对一幅图做横向镜像"));

     undoAction = new QAction(QIcon("undo.png"),"撤销",this);
     connect(undoAction,SIGNAL(triggered()),this,SLOT(undo()));

     redoAction = new QAction(QIcon("redo.png"),"重做",this);
     connect(redoAction,SIGNAL(triggered()),showWidget->text,SLOT(redo()));

}

void Editor::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(NewFileAction);
    fileMenu->addAction(PrintTextAction);
    fileMenu->addAction(PrintImageAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    zoomMenu = menuBar()->addMenu(tr("编辑"));
    zoomMenu->addAction(copyAction);
    zoomMenu->addAction(cutAction);
    zoomMenu->addAction(pasteAction);
    zoomMenu->addAction(aboutAction);
    zoomMenu->addSeparator();
    zoomMenu->addAction(zoomInAction);
    zoomMenu->addAction(zoomOutAction);

    rotateMenu = menuBar()->addMenu(tr("旋转"));
    rotateMenu->addAction(rotate90Action);
    rotateMenu->addAction(rotate180Action);
    rotateMenu->addAction(rotate270Action);

    mirrorMenu = menuBar()->addMenu(tr("镜像"));
    mirrorMenu->addAction(mirrorVerticalAction);
    mirrorMenu->addAction(mirrorHorizontalAction);
}




void Editor::createToolBars()
{
    fileTool = addToolBar("File");
    fileTool->addAction(openFileAction);
    fileTool->addAction(NewFileAction);
    fileTool->addAction(PrintTextAction);
    fileTool->addAction(PrintImageAction);

    zoomTool = addToolBar("Edit");
    zoomTool->addAction(copyAction);
    zoomTool->addAction(cutAction);
    zoomTool->addAction(pasteAction);
    zoomTool->addSeparator();
    zoomTool->addAction(zoomInAction);
    zoomTool->addAction(zoomOutAction);

    rotateTool = addToolBar("rotate");
    rotateTool->addAction(rotate90Action);
    rotateTool->addAction(rotate180Action);
    rotateTool->addAction(rotate270Action);

    doToolBar = addToolBar("doEdit");
    doToolBar->addAction(undoAction);
    doToolBar->addAction(redoAction);

    fileTool->setAllowedAreas(Qt::TopToolBarArea|Qt::LeftToolBarArea);
    fileTool->setMovable(false);

}



