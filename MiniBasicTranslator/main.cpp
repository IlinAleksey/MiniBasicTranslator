#include "Hashtable.h"
#include "HashtableDel.h"
#include "Lexer.h"
#include "Synt.h"
#include <string>
#include "HtmlLogger.h"
int main()
{
	/*Lexer lxr;
	lxr.start("data.txt");*/
	Synt snt;
	snt.start("data.txt");
	snt.start_syntax();

	/*HtmlLogger html_logger = HtmlLogger();
	html_logger.InitNewTable();
	html_logger.PushToTableTop("1");
	html_logger.PushToTableTop("1");
	html_logger.PushToTableTop("1");
	html_logger.PushToTableTop("1");
	html_logger.PushToTableTop("1");
	html_logger.AddTable();
	html_logger.InitNewTable();
	html_logger.PushToTableTop("1");
	html_logger.PushToTableTop("1");
	html_logger.PushToTableTop("1");
	html_logger.AddTable();
	html_logger.SaveFile();*/
	return 0;
}