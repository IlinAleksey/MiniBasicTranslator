#include "Synt.h"


Synt::Synt() :m_fsm_table(SyntStackSymbol::LAST_SYNTSTACKSYMBOL, std::vector<synt_method>(SyntInputSymbol::LAST_SYNTINPUTSYMBOL, &Synt::f_omega))
{
	m_fsm_table[PROGRAM][STRING] = &Synt::f_1;

	m_fsm_table[BODY][ASSIGN] = &Synt::f_4;
	m_fsm_table[BODY][ENDsnt] = &Synt::f_2;

	m_fsm_table[OTHERLINES][STRING] = &Synt::f_13;

	m_fsm_table[EXPRESSION][OPERAND] = &Synt::f_14;

	m_fsm_table[TERM][OPERAND] = &Synt::f_20;

	m_fsm_table[FACTOR][OPERAND] = &Synt::f_24;

	m_fsm_table[PRIMARY][OPERAND] = &Synt::f_28;

	m_fsm_table[FLIST][STRING] = &Synt::f_26;
	m_fsm_table[FLIST][ADDITION] = &Synt::f_26;
	m_fsm_table[FLIST][SUBTRACT] = &Synt::f_26;
	m_fsm_table[FLIST][MULTIPLICATION] = &Synt::f_26;
	m_fsm_table[FLIST][DIVISION] = &Synt::f_26;
	m_fsm_table[FLIST][EXPONENT] = &Synt::f_25;

	m_fsm_table[TLIST][STRING] = &Synt::f_23;
	m_fsm_table[TLIST][ADDITION] = &Synt::f_23;
	m_fsm_table[TLIST][SUBTRACT] = &Synt::f_26;
	m_fsm_table[TLIST][MULTIPLICATION] = &Synt::f_21;
	m_fsm_table[FLIST][DIVISION] = &Synt::f_22;

	m_fsm_table[ELIST][STRING] = &Synt::f_19;
	m_fsm_table[ELIST][ADDITION] = &Synt::f_17;
	m_fsm_table[ELIST][SUBTRACT] = &Synt::f_18;

	m_fsm_table[ENDst][ENDsnt] = &Synt::a;

	m_fsm_table[BOTTOM][END_MARKER] = &Synt::c;

	m_fsm_table[ASSIGNact][STRING] = &Synt::d;

	m_fsm_table[ADDITIONact][STRING] = &Synt::l;
	m_fsm_table[ADDITIONact][ADDITION] = &Synt::l;
	m_fsm_table[ADDITIONact][SUBTRACT] = &Synt::l;
	m_fsm_table[ADDITIONact][MULTIPLICATION] = &Synt::l;
	m_fsm_table[ADDITIONact][DIVISION] = &Synt::l;
	m_fsm_table[ADDITIONact][EXPONENT] = &Synt::l;

	m_fsm_table[SUBTRACTIONact][STRING] = &Synt::m;
	m_fsm_table[SUBTRACTIONact][ADDITION] = &Synt::m;
	m_fsm_table[SUBTRACTIONact][SUBTRACT] = &Synt::m;
	m_fsm_table[SUBTRACTIONact][MULTIPLICATION] = &Synt::m;
	m_fsm_table[SUBTRACTIONact][DIVISION] = &Synt::m;
	m_fsm_table[SUBTRACTIONact][EXPONENT] = &Synt::m;

	m_fsm_table[MULTIPLICATIONact][STRING] = &Synt::n;
	m_fsm_table[MULTIPLICATIONact][ADDITION] = &Synt::n;
	m_fsm_table[MULTIPLICATIONact][SUBTRACT] = &Synt::n;
	m_fsm_table[MULTIPLICATIONact][MULTIPLICATION] = &Synt::n;
	m_fsm_table[MULTIPLICATIONact][DIVISION] = &Synt::n;
	m_fsm_table[MULTIPLICATIONact][EXPONENT] = &Synt::n;

	m_fsm_table[DIVIOSIONact][STRING] = &Synt::o;
	m_fsm_table[DIVIOSIONact][ADDITION] = &Synt::o;
	m_fsm_table[DIVIOSIONact][SUBTRACT] = &Synt::o;
	m_fsm_table[DIVIOSIONact][MULTIPLICATION] = &Synt::o;
	m_fsm_table[DIVIOSIONact][DIVISION] = &Synt::o;
	m_fsm_table[DIVIOSIONact][EXPONENT] = &Synt::o;

	m_fsm_table[EXPONENTact][STRING] = &Synt::p;
	m_fsm_table[EXPONENTact][ADDITION] = &Synt::p;
	m_fsm_table[EXPONENTact][SUBTRACT] = &Synt::p;
	m_fsm_table[EXPONENTact][MULTIPLICATION] = &Synt::p;
	m_fsm_table[EXPONENTact][DIVISION] = &Synt::p;
	m_fsm_table[EXPONENTact][EXPONENT] = &Synt::p;

	CTL = 0;
	top_position = -1;
	mainstack = new int[1000];
}


Synt::~Synt()
{
}

void Synt::f_1()
{
	/*
	replaces 

	<program>

	with
	
	<body>
	END

	adds new atom numline, puts number of current line into LN register and shifts
	*/ 
	pop();
	push(SyntStackSymbol::ENDst);
	push(SyntStackSymbol::BODY);
	AddAtom(AtomClass::NUMLINEatom, value_register);
	LN = value_register;
	shift();

}

void Synt::f_2()
{/*
	pops top pf the stack
	then it holds
	*/ 
	pop();
}

void Synt::f_4()
{
	/*
	replaces

	<body>

	with

	<expression>
	element 2
	{ASSIGN}
	p
	element 1
	<other lines>

	where element 2 contains a pointer to element 1
	then it shifts
	*/
	pop();
	push(SyntStackSymbol::OTHERLINES);
	push(0);
	push(value_register);
	push(SyntStackSymbol::ASSIGNact);
	push(int(&mainstack[top_position - 2]));
	push(SyntStackSymbol::EXPRESSION);
	shift();
}

void Synt::f_13()
{
	/*
	replaces

	<other lines>

	with

	<body>
	adds new atom numline, puts number of current line into LN register
	then it shifts
	*/
	pop();
	push(SyntStackSymbol::BODY);
	AddAtom(AtomClass::NUMLINEatom, value_register);
	LN = value_register;
	shift();
}

void Synt::f_14()
{
	/*
	replaces

	<expression>
	element 0 

	with

	<term>
	element 2
	<E list>
	element 1
	element 0

	where element 2 contains a pointer to element 1
	then it holds
	*/
	pop();
	push(0);
	push(SyntStackSymbol::ELIST);
	push(int(&mainstack[top_position - 1]));
	push(SyntStackSymbol::TERM);
}

void Synt::f_17()
{
	/*
	replaces

	<E list>
	p
	element 0

	with

	<term>
	element 2
	{ADDITION}
	p
	element 1
	r
	<E list>
	r
	element 0

	where element 2 contains a pointer to element 1, r is a result of NOVT()
	then it shifts
	*/
	int r = int(NOVT());
	int p = mainstack[top_position - 1];
	mainstack[top_position - 1] = r;
	push(r);
	push(0);
	push(p);
	push(SyntStackSymbol::ADDITIONact);
	push(int(&mainstack[top_position - 2]));
	push(SyntStackSymbol::TERM);
	shift();
}

void Synt::f_18()
{
	/*
	replaces

	<E list>
	p
	element 0

	with

	<term>
	element 2
	{SUBTRACT}
	p
	element 1
	r
	<E list>
	r
	element 0

	where element 2 contains a pointer to element 1, r is a result of NOVT()
	then it shifts
	*/
	int r = int(NOVT());
	int p = mainstack[top_position - 1];
	mainstack[top_position - 1] = r;
	push(r);
	push(0);
	push(p);
	push(SyntStackSymbol::SUBTRACTIONact);
	push(int(&mainstack[top_position - 2]));
	push(SyntStackSymbol::TERM);
	shift();
}

void Synt::f_19()
{
	/*
	currently first elements of stack look like this

	<E list>	[top]
	element 1	[top-1]
	element 0	[top-2]

	currently element 0 contains a pointer to some element and element 1 contains
	a value of an identifier or a constant, this method puts value of element 1
	into some element, then pops <T list>, element 1, element 2

	then it holds
	*/
	int* ptr = (int*) mainstack[top_position - 2];
	*ptr = mainstack[top_position - 1];
	pop();
	pop();
	pop();
}

void Synt::f_20()
{
	/*
	replaces

	<term>
	element 0

	with

	<factor>
	element 2
	<T list>
	element 1
	element 0

	where element 2 contains a pointer to element 1
	then it holds
	*/
	pop();
	push(0);
	push(SyntStackSymbol::TLIST);
	push(int(&mainstack[top_position - 1]));
	push(SyntStackSymbol::FACTOR);
}

void Synt::f_21()
{
	/*
	replaces

	<T list>
	p
	element 0

	with

	<factor>
	element 2
	{MULTIPLICATION}
	p
	element 1
	r
	<T list>
	r
	element 0

	where element 2 contains a pointer to element 1, r is a result of NOVT()
	then it shifts
	*/
	int r = int(NOVT());
	int p = mainstack[top_position - 1];
	mainstack[top_position - 1] = r;
	push(r);
	push(0);
	push(p);
	push(SyntStackSymbol::MULTIPLICATIONact);
	push(int(&mainstack[top_position - 2]));
	push(SyntStackSymbol::FACTOR);
	shift();
}

void Synt::f_22()
{
	/*
	replaces

	<T list>
	p
	element 0

	with

	<factor>
	element 2
	{DIVISION}
	p
	element 1
	r
	<T list>
	r
	element 0

	where element 2 contains a pointer to element 1, r is a result of NOVT()
	then it shifts
	*/
	int r = int(NOVT());
	int p = mainstack[top_position - 1];
	mainstack[top_position - 1] = r;
	push(r);
	push(0);
	push(p);
	push(SyntStackSymbol::DIVIOSIONact);
	push(int(&mainstack[top_position - 2]));
	push(SyntStackSymbol::FACTOR);
	shift();
}

void Synt::f_23()
{
	/*
	currently first elements of stack look like this

	<T list>	[top]
	element 1	[top-1]
	element 0	[top-2]

	currently element 0 contains a pointer to some element and element 1 contains
	a value of an identifier or a constant, this method puts value of element 1
	into some element, then pops <T list>, element 1, element 2

	then it holds
	*/
	int* ptr = (int*) mainstack[top_position - 2];
	*ptr = mainstack[top_position - 1];
	pop();
	pop();
	pop();
}

void Synt::f_24()
{
	/*
	replaces

	<factor>
	element 0

	with

	<primary>
	element 2
	<F list>
	element 1
	element 0

	where element 2 contains a pointer to element 1
	then it holds
	*/
	pop();
	push(0);
	push(SyntStackSymbol::FLIST);
	push(int(&mainstack[top_position - 1]));
	push(SyntStackSymbol::PRIMARY);
}

void Synt::f_25()
{
	/*
	replaces

	<F list>
	p
	element 0

	with

	<primary>
	element 2
	{EXPONENT}
	p
	element 1
	r
	<F list>
	r
	element 0

	where element 2 contains a pointer to element 1, r is a result of NOVT()
	then it shifts
	*/
	int r = int(NOVT());
	int p = mainstack[top_position - 1];
	mainstack[top_position - 1] = r;
	push(r);
	push(0);
	push(p);
	push(SyntStackSymbol::EXPONENTact);
	push(int(&mainstack[top_position - 2]));
	push(SyntStackSymbol::PRIMARY);
	shift();
}

void Synt::f_26()
{
	/*
	currently first elements of stack look like this

	<F list>	[top]
	element 1	[top-1]
	element 0	[top-2]

	currently element 0 contains a pointer to some element and element 1 contains
	a value of an identifier or a constant, this method puts value of element 1
	into some element, then pops <F list>, element 1, element 2

	then it holds
	*/
	int* ptr = (int*) mainstack[top_position - 2];
	*ptr = mainstack[top_position - 1];
	pop();
	pop();
	pop();
}

void Synt::f_28()
{
	/*
	currently first elements of stack look like this

	<primary>	[top]
	element 1	[top-1]

	currentl element 1 contains a pointer to some element and value_register a value of an 
	identifier 	or a constant, this method puts value of value_register into some element,
	then pops <primary>	and element 1,
	then it shifts
	*/
	int* ptr = (int*)mainstack[top_position - 1];
	*ptr = value_register;
	pop();
	pop();
	shift();
}

void Synt::a()
{
	/*
	pops top pf the stack
	then it shifts
	*/
	pop();
	shift();
}

void Synt::c()
{
	/*accept*/
	AddAtom(AtomClass::ENDatom);
	pop();
}

void Synt::d()
{
	/*
	currently first elements of stack look like this

	{ASSIGN}	[top]
	element 2	[top-1]
	element 1	[top-2]

	adds new atom ASSIGN(element 1, element 0)

	then it holds
	*/
	AddAtom(AtomClass::ASSIGNatom,
		mainstack[top_position - 1],
		mainstack[top_position - 2]);
	pop();
	pop();
	pop();
}

void Synt::l()
{
	/*
	currently first elements of stack look like this

	{ADDITION}	[top]
	element 2	[top-1]
	element 1	[top-2]
	element 0	[top-3]

	adds new atom ADDITION(element 2, element 1, element 0)

	then it holds
	*/
	AddAtom(AtomClass::ADDITIONatom,
		mainstack[top_position - 1],
		mainstack[top_position - 2],
		mainstack[top_position - 3]);
	pop();
	pop();
	pop();
	pop();
}

void Synt::m()
{
	/*
	currently first elements of stack look like this

	{SUBTRACT}	[top]
	element 2	[top-1]
	element 1	[top-2]
	element 0	[top-3]

	adds new atom ADDITION(element 2, element 1, element 0)

	then it holds
	*/
	AddAtom(AtomClass::SUBTRACTIONatom,
		mainstack[top_position - 1],
		mainstack[top_position - 2],
		mainstack[top_position - 3]);
	pop();
	pop();
	pop();
	pop();
}

void Synt::n()
{
	/*
	currently first elements of stack look like this

	{MULTIPLICATION}	[top]
	element 2			[top-1]
	element 1			[top-2]
	element 0			[top-3]

	adds new atom ADDITION(element 2, element 1, element 0)

	then it holds
	*/
	AddAtom(AtomClass::MULTIPLICATIONatom,
		mainstack[top_position - 1],
		mainstack[top_position - 2],
		mainstack[top_position - 3]);
	pop();
	pop();
	pop();
	pop();
}

void Synt::o()
{
	/*
	currently first elements of stack look like this

	{DIVISION}	[top]
	element 2	[top-1]
	element 1	[top-2]
	element 0	[top-3]

	adds new atom ADDITION(element 2, element 1, element 0)

	then it holds
	*/
	AddAtom(AtomClass::DIVISIONatom,
		mainstack[top_position - 1],
		mainstack[top_position - 2],
		mainstack[top_position - 3]);
	pop();
	pop();
	pop();
	pop();
}

void Synt::p()
{
	/*
	currently first elements of stack look like this

	{EXPONENT}	[top]
	element 2	[top-1]
	element 1	[top-2]
	element 0	[top-3]

	adds new atom ADDITION(element 2, element 1, element 0)

	then it holds
	*/
	AddAtom(AtomClass::EXPONENTatom,
		mainstack[top_position - 1],
		mainstack[top_position - 2],
		mainstack[top_position - 3]);
	pop();
	pop();
	pop();
	pop();
}

void Synt::f_omega()
{

}

void Synt::pop()
{
	top_position--;
}
void Synt::push(int element)
{
	mainstack[top_position + 1] = element;
	top_position++;
}
void Synt::top(int position)
{
	
}
void Synt::shift()
{
	CTL++;
}

void Synt::transliterator(lexeme_token tkn)
{
	switch (tkn.m_class)
	{
	case label:
		input_register = SyntInputSymbol::STRING;
		break;
	case identifier:
		input_register = SyntInputSymbol::OPERAND;
		break;
	case arithmetic_operation:
		switch (tkn.m_value)
		{
		case 1:
			input_register = SyntInputSymbol::ADDITION;
			break;
		case 2:
			input_register = SyntInputSymbol::SUBTRACT;
			break;
		case 3:
			input_register = SyntInputSymbol::MULTIPLICATION;
			break;
		case 4:
			input_register = SyntInputSymbol::DIVISION;
			break;
		case 5:
			input_register = SyntInputSymbol::EXPONENT;
			break;
		default:
			break;
		}
		break;
	case relationship_operation:
		input_register = SyntInputSymbol::RELATIONSHIP;
		break;
	case end_of_loop:
		input_register = SyntInputSymbol::ENDOFLOOP;
		break;
	case assignment:
		input_register = SyntInputSymbol::ASSIGN;
		break;
	case FOR:
		input_register = SyntInputSymbol::FORsnt;
		break;
	case transfer:
		input_register = SyntInputSymbol::GOTOSYNT;
		break;
	case transfer_sub:
		input_register = SyntInputSymbol::GOTOSUBSYNT;
		break;
	case left_parenthesis:
		input_register = SyntInputSymbol::LEFTPAR;
		break;
	case right_parenthesis:
		input_register = SyntInputSymbol::RIGHTPAR;
		break;
	case IF:
		input_register = SyntInputSymbol::IFsnt;
		break;
	case RETURN:
		input_register = SyntInputSymbol::RETURNsnt;
		break;
	case END:
		input_register = SyntInputSymbol::ENDsnt;
		break;
	case TO:
		input_register = SyntInputSymbol::TOsnt;
		break;
	case STEP:
		input_register = SyntInputSymbol::STEPsnt;
		break;
	case REM:
		input_register = SyntInputSymbol::RETURNsnt;
		break;
	case WHILE:
		input_register = SyntInputSymbol::ERROR;
		break;
	case ENDW:
		input_register = SyntInputSymbol::ERROR;
		break;
	case ERROR_LEXEME:
		input_register = SyntInputSymbol::ERROR;
		break;
	case END_OF_FILE:
		input_register = SyntInputSymbol::END_MARKER;
		break;
	case LAST_LEXEME_TOKEN_CLASS:
		break;
	default:
		break;
	}
	value_register = tkn.m_value;
}

void Synt::AddAtom(AtomClass atomclass, int a1, int a2, int a3, int a4)
{
	TA.push_back({ atomclass, a1, a2, a3, a4 });
}

void Synt::start_syntax()
{
	push(SyntStackSymbol::BOTTOM);
	push(SyntStackSymbol::PROGRAM);
	while (top_position >= 0)
	{
		transliterator(UTL[CTL]);
		(this->*m_fsm_table[mainstack[top_position]][input_register])();
		for (int i = top_position; i >=0; i--)
		{
			std::cout << mainstack[i] << std::endl;

		}
		std::cout  << std::endl;
	}
	int a = 2;
	return;
}