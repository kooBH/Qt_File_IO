#include "simple_file_IO_GUI.h"

void simple_file_IO_GUI::open()
{
	std::ifstream f;
	QString QfileName = QFileDialog::getOpenFileName(this, tr("Open File"), "default name", tr("default type (*.a *.b *.c)"));
	
	
	if (QfileName.isEmpty())
	{
		log("You canceled");
		return;
	}
	f.open(QfileName.toStdString());
	log("Open : " + QfileName);
	
	f.close();
}

void simple_file_IO_GUI::save()
{
	std::ofstream f;
	QString QfileName =  QFileDialog::getSaveFileName(this, tr("Save Directiory"), "default name", tr("default type (*.a *.b *.c)"));
	if (QfileName.isEmpty())
	{
		log("You canceled");
		return;
	}
	f.open(QfileName.toStdString());
	log("Save : " + QfileName);

	f.close();

	
}

simple_file_IO_GUI::simple_file_IO_GUI(QWidget *parent)
	: QMainWindow(parent)
{
	QWidget *widget = new QWidget;
	setCentralWidget(widget);

	QWidget *topFiller = new QWidget;
	topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	infoLabel = new QLabel("");
	infoLabel->setFrameStyle(QFrame::Plain | QFrame::Box);
	infoLabel->setStyleSheet("background-color: rgb(255, 255, 255);");
	infoLabel->setAlignment(Qt::AlignTop);

	QWidget *bottomFiller = new QWidget;
	bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	QVBoxLayout *layout = new QVBoxLayout;
	layout->setMargin(5);
	//layout->addWidget(topFiller);
	layout->addWidget(infoLabel);
	//layout->addWidget(bottomFiller);
	widget->setLayout(layout);

	createActions();
	createMenus();
	
	setWindowTitle(tr("File IO"));
	setMinimumSize(160, 160);
	resize(480, 340);
	
}

void simple_file_IO_GUI::log(QString in)
{
	QString prev = infoLabel->text();
	QString next;
	if (prev != "")
		next = prev + "\n" + in;
	else
		next = in;
	infoLabel->setText(next);
}





void simple_file_IO_GUI::createActions()
{

	openAct = new QAction(tr("&Open..."), this);
	openAct->setShortcuts(QKeySequence::Open);
	openAct->setStatusTip(tr("Open an existing file"));
	connect(openAct, &QAction::triggered, this, &simple_file_IO_GUI::open);

	saveAct = new QAction(tr("&Save"), this);
	saveAct->setShortcuts(QKeySequence::Save);
	saveAct->setStatusTip(tr("Save the document to disk"));
	connect(saveAct, &QAction::triggered, this, &simple_file_IO_GUI::save);
	
	exitAct = new QAction(tr("E&xit"), this);
	exitAct->setShortcuts(QKeySequence::Quit);
	exitAct->setStatusTip(tr("Exit the application"));
	//종료하는건 이미 있음
	connect(exitAct, &QAction::triggered, this, &QWidget::close);

}

void simple_file_IO_GUI::createMenus()
{
	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(openAct);
	fileMenu->addAction(saveAct);
	fileMenu->addAction(exitAct);
	
}