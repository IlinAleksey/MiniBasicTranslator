#pragma once
#include "Lexer.h"
#include <stack>
#include <vector>
#include "HtmlLogger.h"

class Synt;
enum SyntInputSymbol
{
	STRING, OPERAND, RELATIONSHIP, ENDOFLOOP, ASSIGN, FORsnt, GOTOSYNT, GOTOSUBSYNT, LEFTPAR,
	RIGHTPAR, IFsnt, RETURNsnt, ENDsnt, TOsnt, STEPsnt, ADDITION, SUBTRACT, MULTIPLICATION, DIVISION,
	EXPONENT, ERROR, END_MARKER, LAST_SYNTINPUTSYMBOL
};
enum SyntStackSymbol
{
	PROGRAM, BODY, STEPst, OTHERLINES, EXPRESSION, TERM, FACTOR, PRIMARY, ELIST, TLIST, FLIST,
	RELSATIONSHIPst, ENDOFLOOPst,	GOTOst, RIGHTPARst, ENDst, TOst, BOTTOM, ASSIGNact, IFact,
	KEEPact, LABELact, CHECKact, CONTROLact, INCREASEact, GOTOact, ADDITIONact,	SUBTRACTIONact,
	MULTIPLICATIONact, DIVIOSIONact, EXPONENTact, PLUSact, MINUSact, LAST_SYNTSTACKSYMBOL
};
enum AtomClass
{
	ENDatom, NUMLINEatom, ASSIGNatom, GOTOatom, KEEPGOTOatom, RETURNGOTOatom, IFGOTOatom, KEEPatom,
	LABELatom, CHECKatom, INCREASEatom, ADDITIONatom, SUBTRACTIONatom, MULTIPLICATIONatom,
	DIVISIONatom, EXPONENTatom, PLUSatom, MINUSatom
};
struct Atom
{
	AtomClass atom_class;
	int a1;
	int a2;
	int a3;
	int a4;
};
enum StackElementClass
{
	Nonterminal, Action, Pointer, Value
};
struct StackElement
{
	StackElementClass type;
	int value;
};
typedef void(Synt::*synt_method)();
class Synt :
	public Lexer
{
	std::vector<Atom> TA;

	void transliterator(lexeme_token tkn);
	SyntInputSymbol input_register;
	int value_register;

	StackElement* mainstack;
	int mainstack_size;
	int top_position;
	void pop();
	void push(StackElement element);
	void top(int position = 0);
	void shift();

	int LN;
	int CTL;

	std::vector<std::vector<synt_method>> m_fsm_table;

	void f_1();
	void f_2();
	void f_4();
	void f_13();
	void f_14();
	void f_17();
	void f_18();
	void f_19();
	void f_20();
	void f_21();
	void f_22();
	void f_23();
	void f_24();
	void f_25();
	void f_26();
	void f_27();
	void f_28();

	void a();
	void c();
	void d();
	void l();
	void m();
	void n();
	void o();
	void p();

	void f_omega();

	void AddAtom(AtomClass atomclass, int a1 = 0, int a2 = 0, int a3 = 0, int a4 = 0);

	int* NOVT() { return new int; }

	std::string format_stack_element(StackElement element);
	HtmlLogger html_logger;
	void log_current_state();
public:
	Synt();
	~Synt();
	void start_syntax();
};

