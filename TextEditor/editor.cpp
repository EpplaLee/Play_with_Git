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
    delete ui;
}
