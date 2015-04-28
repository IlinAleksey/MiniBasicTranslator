#include "Lexer.h"
#include <fstream>
#include <string>
#include <math.h>
#include <ctype.h>
#include <iomanip>

std::vector<std::string> arr_lexemes = { "", "label", "identifier", "arithmetic_operation",
"relationship_operation", "NEXT", "LET", "FOR", "GOTO",
"GOSUB", "left_parenthesis", "right_parenthesis", "IF", "RETURN", "END", "TO", "STEP", "REM",
"ERROR_LEXEME", "END_OF_FILE", "LAST_LEXEME_TOKEN_CLASS" };

Lexer::Lexer()
{
	m_init_vector = {
		0, //a
		0, //b
		0, //c
		0, //d
		1, //e
		3, //f
		5, //g
		0,
		11, //i
		0, 0,
		12, //l
		0,
		14, //n
		0,
		0, //p
		0, 
		17, //r
		23, //s
		26, //t
		0, 0, 0, 0, 0, 0
	};
	m_transition_table = {
		{},
		{ 'N', 0, &Lexer::B1d },
		{ 'D', 0, &Lexer::A2q },
		{ 'O', 0, &Lexer::B1d },
		{ 'R', 0, &Lexer::F1b },
		{ 'O', 0, &Lexer::B1d },
		{ 'T', 8, &Lexer::B1d },
		{ 'O', 0, &Lexer::E1a },
		{ 'S', 0, &Lexer::B1d },
		{ 'U', 0, &Lexer::B1d },
		{ 'B', 0, &Lexer::E1b },
		{ 'F', 0, &Lexer::A2r },
		{ 'E', 0, &Lexer::B1d },
		{ 'T', 0, &Lexer::F1a },
		{ 'E', 0, &Lexer::B1d },
		{ 'X', 0, &Lexer::B1d },
		{ 'T', 0, &Lexer::C1a },
		{ 'E', 0, &Lexer::B1d },
		{ 'T', 22, &Lexer::B1d },
		{ 'U', 0, &Lexer::B1d },
		{ 'R', 0, &Lexer::B1d },
		{ 'N', 0, &Lexer::A2s },
		{ 'M', 0, &Lexer::G1a },
		{ 'T', 0, &Lexer::B1d },
		{ 'E', 0, &Lexer::B1d },
		{ 'P', 0, &Lexer::A2t },
		{ 'O', 0, &Lexer::A2u }
		

	};
	UTO = new float[500];
	for (int i = 0; i < 100; i++)
	{
		UTO[i] = 0;
	}
	NTO = 278;
	UTL = new lexeme_token[100];
	for (int i = 0; i < 100; i++)
	{
		UTL[i] = lexeme_token{ lexeme_token_class(-1), -1 };
	}
	NTL = 0;
	RSOS = &Lexer::A1;
	RSTR = 0;
	RU = 0;
	ROB = 0;
	RZ = 0;
	RP = 0;
	ROT = 0;
	RS = 0;
	RCH = 0;
	ROW = 1;
	COL = 1;
}


Lexer::~Lexer()
{
	delete [] UTO;
	delete [] UTL;
}

void Lexer::A1()
{
	switch (RK)
	{
	case Lexer::letter:
		error_method("error1");
		break;
	case Lexer::digit:
		E2a();
		break;
	case Lexer::arithmetic:
		error_method("error2");
		break;
	case Lexer::relationship:
		error_method("error3");
		break;
	case Lexer::left_par:
		error_method("error4");
		break;
	case Lexer::right_par:
		error_method("error5");
		break;
	case Lexer::dot:
		error_method("error6");
		break;
	case Lexer::CR:
		break;
	case Lexer::newline:
		break;
	case Lexer::eof:
		EXIT1();
		break;
	case Lexer::error:
		error_method("error7");
		break;
	case Lexer::last_transliterator_token_class:
		error_method("error7");
		break;
	default:
		break;
	}
}
void Lexer::A2()
{
	switch (RK)
	{
	case Lexer::letter:
		C2a();
		break;
	case Lexer::digit:
		D1a();
		break;
	case Lexer::arithmetic:
		A2a();
		break;
	case Lexer::relationship:
		H1a();
		break;
	case Lexer::left_par:
		A2h();
		break;
	case Lexer::right_par:
		A3b();
		break;
	case Lexer::dot:
		RSOS = &Lexer::D6;
		break;
	case Lexer::CR:
		RSOS = &Lexer::A2;
		break;
	case Lexer::newline:
		RSOS = &Lexer::A1;
		break;
	case Lexer::eof:
		EXIT1();
		break;
	case Lexer::error:
		error_method("error");
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::A3()
{
	switch (RK)
	{
	case Lexer::letter:
		B1a();
		break;
	case Lexer::digit:
		D1a();
		break;
	case Lexer::arithmetic:
		A2a();
		break;
	case Lexer::relationship:
		H1a();
		break;
	case Lexer::left_par:
		A2h();
		break;
	case Lexer::right_par:
		A3b();
		break;
	case Lexer::dot:
		RSOS = &Lexer::D6;
		break;
	case Lexer::CR:
		RSOS = &Lexer::A3;
		break;
	case Lexer::newline:
		RSOS = &Lexer::A1;
		break;
	case Lexer::eof:
		EXIT1();
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::B1()
{
	switch (RK)
	{
	case Lexer::letter:
		M1();
		break;
	case Lexer::digit:
		error_method("errorB1 1");
		break;
	case Lexer::arithmetic:
		error_method("errorB1 2");
		break;
	case Lexer::relationship:
		error_method("errorB1 3");
		break;
	case Lexer::left_par:
		error_method("errorB1 4");
		break;
	case Lexer::right_par:
		error_method("errorB1 5");
		break;
	case Lexer::dot:
		error_method("errorB1 6");
		break;
	case Lexer::CR:
		RSOS = &Lexer::B1;
		break;
	case Lexer::newline:
		error_method("errorB1 8");
		break;
	case Lexer::eof:
		error_method("errorB1 9");
		break;
	case Lexer::error:
		error_method("errorB1 10");
		break;
	case Lexer::last_transliterator_token_class:
		error_method("error");
		break;
	default:
		break;
	}
}
void Lexer::C1()
{
	switch (RK)
	{
	case Lexer::letter:
		C2d();
		break;
	case Lexer::digit:
		break;
	case Lexer::arithmetic:
		break;
	case Lexer::relationship:
		break;
	case Lexer::left_par:
		break;
	case Lexer::right_par:
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		RSOS = &Lexer::C1;
		break;
	case Lexer::newline:
		break;
	case Lexer::eof:
		EXIT3();
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::C2()
{
	switch (RK)
	{
	case Lexer::letter:
		B1b();
		break;
	case Lexer::digit:
		A3a();
		break;
	case Lexer::arithmetic:
		A2g();
		break;
	case Lexer::relationship:
		H1b();
		break;
	case Lexer::left_par:
		A2k();
		break;
	case Lexer::right_par:
		A3c();
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		RSOS = &Lexer::C2;
		break;
	case Lexer::newline:
		A1a();
		break;
	case Lexer::eof:
		EXIT4();
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::D1()
{
	switch (RK)
	{
	case Lexer::letter:
		M2();
		break;
	case Lexer::digit:
		D1b();
		break;
	case Lexer::arithmetic:
		A2c();
		break;
	case Lexer::relationship:
		H1c();
		break;
	case Lexer::left_par:
		A2l();
		break;
	case Lexer::right_par:
		A3d();
		break;
	case Lexer::dot:
		D2c();
		break;
	case Lexer::CR:
		RSOS = &Lexer::D1;
		break;
	case Lexer::newline:
		A1b();
		break;
	case Lexer::eof:
		EXIT3();
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::D2()
{
	switch (RK)
	{
	case Lexer::letter:
		M3();
		break;
	case Lexer::digit:
		D2a();
		break;
	case Lexer::arithmetic:
		A2d();
		break;
	case Lexer::relationship:
		H1d();
		break;
	case Lexer::left_par:
		A2m();
		break;
	case Lexer::right_par:
		A3e();
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		RSOS = &Lexer::D2;
		break;
	case Lexer::newline:
		A1c();
		break;
	case Lexer::eof:
		EXIT4();
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::D3()
{
	switch (RK)
	{
	case Lexer::letter:
		break;
	case Lexer::digit:
		D5a();
		break;
	case Lexer::arithmetic:
		D4a();
		break;
	case Lexer::relationship:
		break;
	case Lexer::left_par:
		break;
	case Lexer::right_par:
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		RSOS = &Lexer::D3;
		break;
	case Lexer::newline:
		break;
	case Lexer::eof:
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::D4()
{
	switch (RK)
	{
	case Lexer::letter:
		break;
	case Lexer::digit:
		D5b();
		break;
	case Lexer::arithmetic:
		break;
	case Lexer::relationship:
		break;
	case Lexer::left_par:
		break;
	case Lexer::right_par:
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		RSOS = &Lexer::D4;
		break;
	case Lexer::newline:
		break;
	case Lexer::eof:
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::D5()
{
	switch (RK)
	{
	case Lexer::letter:
		B1c();
		break;
	case Lexer::digit:
		D5c();
		break;
	case Lexer::arithmetic:
		A2e();
		break;
	case Lexer::relationship:
		H1c();
		break;
	case Lexer::left_par:
		A2n();
		break;
	case Lexer::right_par:
		A3f();
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		RSOS = &Lexer::D5;
		break;
	case Lexer::newline:
		A1d();
		break;
	case Lexer::eof:
		EXIT5();
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::D6()
{
	switch (RK)
	{
	case Lexer::letter:
		break;
	case Lexer::digit:
		D2b();
		break;
	case Lexer::arithmetic:
		break;
	case Lexer::relationship:
		break;
	case Lexer::left_par:
		break;
	case Lexer::right_par:
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		RSOS = &Lexer::D6;
		break;
	case Lexer::newline:
		break;
	case Lexer::eof:
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::E1()
{
	switch (RK)
	{
	case Lexer::letter:
		break;
	case Lexer::digit:
		E2b();
		break;
	case Lexer::arithmetic:
		break;
	case Lexer::relationship:
		break;
	case Lexer::left_par:
		break;
	case Lexer::right_par:
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		RSOS = &Lexer::E1;
		break;
	case Lexer::newline:
		break;
	case Lexer::eof:
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::E2()
{
	switch (RK)
	{
	case Lexer::letter:
		B1e();
		break;
	case Lexer::digit:
		E2c();
		break;
	case Lexer::arithmetic:
		A2f();
		break;
	case Lexer::relationship:
		H1f();
		break;
	case Lexer::left_par:
		A2j();
		break;
	case Lexer::right_par:
		A3g();
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		RSOS = &Lexer::E2;
		break;
	case Lexer::newline:
		A1e();
		break;
	case Lexer::eof:
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::F1()
{
	switch (RK)
	{
	case Lexer::letter:
		F2a();
		break;
	case Lexer::digit:
		break;
	case Lexer::arithmetic:
		break;
	case Lexer::relationship:
		break;
	case Lexer::left_par:
		break;
	case Lexer::right_par:
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		RSOS = &Lexer::F1;
		break;
	case Lexer::newline:
		break;
	case Lexer::eof:
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::F2()
{
	switch (RK)
	{
	case Lexer::letter:
		break;
	case Lexer::digit:
		F3a();
		break;
	case Lexer::arithmetic:
		break;
	case Lexer::relationship:
		A2o();
		break;
	case Lexer::left_par:
		break;
	case Lexer::right_par:
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		RSOS = &Lexer::F2;
		break;
	case Lexer::newline:
		break;
	case Lexer::eof:
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::F3()
{
	switch (RK)
	{
	case Lexer::letter:
		break;
	case Lexer::digit:
		break;
	case Lexer::arithmetic:
		break;
	case Lexer::relationship:
		A2o();
		break;
	case Lexer::left_par:
		break;
	case Lexer::right_par:
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		RSOS = &Lexer::F3;
		break;
	case Lexer::newline:
		break;
	case Lexer::eof:
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::G1()
{
	switch (RK)
	{
	case Lexer::letter:
		RSOS = &Lexer::G1;
		break;
	case Lexer::digit:
		RSOS = &Lexer::G1;
		break;
	case Lexer::arithmetic:
		RSOS = &Lexer::G1;
		break;
	case Lexer::relationship:
		RSOS = &Lexer::G1;
		break;
	case Lexer::left_par:
		RSOS = &Lexer::G1;
		break;
	case Lexer::right_par:
		RSOS = &Lexer::G1;
		break;
	case Lexer::dot:
		RSOS = &Lexer::G1;
		break;
	case Lexer::CR:
		RSOS = &Lexer::G1;
		break;
	case Lexer::newline:
		RSOS = &Lexer::A1;
		break;
	case Lexer::eof:
		EXIT1();
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::H1()
{
	switch (RK)
	{
	case Lexer::letter:
		C2b();
		break;
	case Lexer::digit:
		D1c();
		break;
	case Lexer::arithmetic:
		A2g();
		break;
	case Lexer::relationship:
		A2p();
		break;
	case Lexer::left_par:
		A2k();
		break;
	case Lexer::right_par:
		A3c();
		break;
	case Lexer::dot:
		D6a();
		break;
	case Lexer::CR:
		H1a();
		break;
	case Lexer::newline:
		A1a();
		break;
	case Lexer::eof:
		EXIT2();
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::error_state()
{
	switch (RK)
	{
	case Lexer::letter:
		break;
	case Lexer::digit:
		break;
	case Lexer::arithmetic:
		break;
	case Lexer::relationship:
		break;
	case Lexer::left_par:
		break;
	case Lexer::right_par:
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		break;
	case Lexer::newline:
		RSOS = &Lexer::A1;
		break;
	case Lexer::eof:
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}



void Lexer::A1b( )
{
	DA1D( );
	addLexem();
	RSOS = &Lexer::A1;
}

void Lexer::A1a( )
{
	addLexem();
	RSOS = &Lexer::A1;
}

void Lexer::A1c( )
{
	DA1D( );
	A1a( );
	RSOS = &Lexer::A1;
}

void Lexer::A1d( )
{
	DA3D( );
	A1a( );
	RSOS = &Lexer::A1;
}

void Lexer::A1e( )
{
	DA1E( );
	A1a( );
	RSOS = &Lexer::A1;
}

void Lexer::A2c( )
{
	DA1D( );
	RSOS = &Lexer::A2;
}

void Lexer::A2g( )
{
	addLexem();
	RKL = arithmetic_operation;
	addLexem();
	RSOS = &Lexer::A2;
}

void Lexer::A2a( )
{
	RKL = arithmetic_operation;
	addLexem();
	RSOS = &Lexer::A2;
}

void Lexer::A2b( )
{
	addLexem();
	RSOS = &Lexer::A2;
}

void Lexer::A2d( )
{
	DA2D( );
	A2g( );
}

void Lexer::A2e( )
{
	DA3D( );
	A2g( );
}

void Lexer::A2f( )
{
	DA1E( );
	A2g( );
}

void Lexer::A2j( )
{
	DA1E( );
	RSOS = &Lexer::A2;
}

void Lexer::A2k( )
{
	addLexem();
	RSOS = &Lexer::A2;
}

void Lexer::A2h( )
{
	RKL = left_parenthesis;
	addLexem();
	RSOS = &Lexer::A2;
}

void Lexer::A2l( )
{
	DA1D( );
	A2k( );
	RSOS = &Lexer::A2;
}

void Lexer::A2m( )
{
	DA2D( );
	A2k( );
	RSOS = &Lexer::A2;
}

void Lexer::A2n( )
{
	DA3D( );
	A2k( );
	RSOS = &Lexer::A2;
}

void Lexer::A2o( )
{
	if (RZN != 1)
	{
		error_method("error A2o meth");
	}
	else
	{
		A2b();
	}
}

void Lexer::A2p( )
{
	int new_relationship;
	switch (ROT)
	{
	case less:
		switch (RZN)
		{
		case equal:
			new_relationship = lessorequal;
			break;
		case more:
			new_relationship = notequal;
		default:
			new_relationship = -1;
			break;
		}
		break;
	case more:
		switch (RZN)
		{
		case equal:
			new_relationship = moreorequal;
			break;
		default:
			new_relationship = -1;
			break;
		}
		break;
	case equal:
		new_relationship = -1;
		break;
	default:
		new_relationship = -1;
		break;
	}
	if (new_relationship == -1)
	{
		error_method("error");
	}
	ROT = new_relationship;
	RSOS = &Lexer::A2;
}

void Lexer::A2q( )
{
	RKL = lexeme_token_class::END;
	A2b();
	RSOS = &Lexer::A2;
}

void Lexer::A2r( )
{
	RKL = lexeme_token_class::IF;
	A2b();
	RSOS = &Lexer::A2;
}

void Lexer::A2s( )
{
	RKL = lexeme_token_class::RETURN;
	A2b();
	RSOS = &Lexer::A2;
}

void Lexer::A2t( )
{
	RKL = lexeme_token_class::STEP;
	A2b();
	RSOS = &Lexer::A2;
}

void Lexer::A2u( )
{
	RKL = lexeme_token_class::TO;
	A2b();
	RSOS = &Lexer::A2;
}
void Lexer::A3a()
{
	RZN = (RZN + 1) * 26;
	RU += RZN;
	addLexem();
	RSOS = &Lexer::A3;
}
void Lexer::A3b()
{
	RKL = right_parenthesis;
	addLexem();
	RSOS = &Lexer::A3;
}
void Lexer::A3c()
{
	addLexem();
	RKL = right_parenthesis;
	addLexem();
	RSOS = &Lexer::A3;
}
void Lexer::A3d()
{
	DA1D();
	RSOS = &Lexer::A3;
}
void Lexer::A3e()
{
	DA2D();
	A3c();
	RSOS = &Lexer::A3;
}
void Lexer::A3f()
{
	DA3D();
	A3c();
	RSOS = &Lexer::A3;
}
void Lexer::A3g()
{
	DA1E();
	A3c();
	RSOS = &Lexer::A3;
}

void Lexer::B1a()
{
	ROB = init_vector(RZN - 1);
	if (ROB == 0) error_method("errorB1a func");   //Не уверен в необходимости ветки ELSE
	RSOS = &Lexer::B1;
}
void Lexer::B1b()
{
	addLexem();
	ROB = init_vector(RZN - 1);
	if (ROB == 0) error_method("error B1b func");
	RSOS = &Lexer::B1;
}
void Lexer::B1c()
{
	DA3D();
	RSOS = &Lexer::B1;
}
void Lexer::B1d()
{
	ROB++;
	RSOS = &Lexer::B1;
}
void Lexer::B1e()
{
	DA1E();
	B1b();
	RSOS = &Lexer::B1;
}

void Lexer::C1a()
{
	RKL = end_of_loop;
	RSOS = &Lexer::C1;
}
void Lexer::С1b()
{
	//Нет такой функции
}
void Lexer::C2a()
{
	RKL = identifier;
	RU = RZN;
	RSOS = &Lexer::C2;
}
void Lexer::C2b()
{
	addLexem();
	RKL = identifier;
	RU = RZN;
	RSOS = &Lexer::C2;
}
void Lexer::C2d()
{
	RU = RZN;
	RSOS = &Lexer::C2;
}


void Lexer::D1a()
{
	RKL = identifier;
	RCH = RZN;
	RSOS = &Lexer::D1;
}
void Lexer::D1b()
{
	RCH *= 10;
	RCH += RZN;
	RSOS = &Lexer::D1;
}
void Lexer::D1c()
{
	addLexem();
	RSOS = &Lexer::D1;
}

void Lexer::D2a()
{
	RS++;
	RCH *= 10;
	RCH += RZN;
	RSOS = &Lexer::D2;
}
void Lexer::D2b()
{
	RS = 1;
	RCH = RZN;
	RSOS = &Lexer::D2;

}
void Lexer::D2c()
{
	RS = 0;
	RSOS = &Lexer::D2;
}

void Lexer::D3a()
{
	RS = 0;
	RSOS = &Lexer::D3;
}
void Lexer::D4a( )
{
	switch (RZN)
	{
	case 1:
		RZ = 1;
	case 2:
		RZ = -1;
	default:
		error_method("error D4a func");
		break;
	}
	RSOS = &Lexer::D4;
}


void Lexer::D5a( )
{
	RZN = 1;
	RSOS = &Lexer::D5;
}

void Lexer::D5b( )
{
	RP = RZN;
	RSOS = &Lexer::D5;
}


void Lexer::D5c( )
{
	RP *= 10;
	RP += RZN;
	RSOS = &Lexer::D5;
}

void Lexer::D6a()
{

	RSOS = &Lexer::D6;
}

void Lexer::E1a()
{
	RKL = lexeme_token_class::transfer;
	RSOS = &Lexer::E1;
}
void Lexer::E1b()
{
	RKL = lexeme_token_class::transfer_sub;
	RSOS = &Lexer::E1;
}

void Lexer::E2a()
{
	RKL = lexeme_token_class::label;
	RSTR = RZN;
	RSOS = &Lexer::E2;
}
void Lexer::E2b()
{
	RSTR = RZN;
	RSOS = &Lexer::E2;
}
void Lexer::E2c()
{
	RSTR *= 10;
	RSTR += RZN;
	RSOS = &Lexer::E2;
}

void Lexer::F1a()
{
	RKL = lexeme_token_class::assignment;
	RSOS = &Lexer::F1;
}
void Lexer::F1b()
{
	RKL = lexeme_token_class::FOR;
	RSOS = &Lexer::F1;
}

void Lexer::F2a()
{
	RU = RZN;
	RSOS = &Lexer::F2;
}

void Lexer::F3a()
{
	RZN = (RZN + 1) * 26;
	RU += RZN;
	RSOS = &Lexer::F3;
}

void Lexer::G1a()
{
	RKL = lexeme_token_class::REM;
	RSOS = &Lexer::G1;
}

void Lexer::H1a()
{
	ROT = RZN;
	RKL = lexeme_token_class::relationship_operation;
	RSOS = &Lexer::H1;
}
void Lexer::H1b()
{
	addLexem();
	H1a();
	RSOS = &Lexer::H1;
}
void Lexer::H1c()
{
	DA1D();
	RSOS = &Lexer::H1;
}
void Lexer::H1d()
{
	DA2D();
	H1b();
	RSOS = &Lexer::H1;
}
void Lexer::H1e()
{
	DA3D();
	H1b();
	RSOS = &Lexer::H1;
}
void Lexer::H1f()
{
	DA1E();
	H1b();
	RSOS = &Lexer::H1;
}
void Lexer::M1()
{
	while (ROB != 0)
	{
		if (m_transition_table[ROB].symbol - 'A' + 1 == RZN)
		{
			(this->*m_transition_table[ROB].method)();
			break;
		}
		else
		{
			ROB = m_transition_table[ROB].alternative;
		}
	}
	if (ROB == 0)
	{
		error_method("error");
	}
}
void Lexer::M2()
{
	if (RZN!=5)
	{
		DA1D();
		B1b();
	}
	else
	{
		D3a();
	}
}
void Lexer::M3()
{
	if (RZN != 5)
	{
		DA2D();
		B1b();
	}
	else
	{
		D3();
	}
}
void Lexer::EXIT1()
{
	//"ВЫХОД1:    Загрузить КОНЕЦ МАРКЕР в РЕГИСТР КЛАССА" Что такое КОНЕЦ МАРКЕР?
	RKL = lexeme_token_class::END_OF_FILE;
	addLexem();
}
void Lexer::EXIT2()
{
	addLexem();
}
void Lexer::EXIT3()
{
	DA1D();
}
void Lexer::EXIT4()
{
	DA2D();
	EXIT2();
}
void Lexer::EXIT5()
{
	DA3D();
	EXIT2();
}
void Lexer::EXIT6()
{
	DA1E();
	EXIT2();
}
void Lexer::DA1D()
{
	RP = 0;
	calculateConstant();
}
void Lexer::DA1E()
{
	int pos = UTS.find(RSTR);
	std::cout << UTS << std::endl;
	if (pos != -1)
	{
		RU = pos;
	}
	else
	{
		RU = UTS.add(RSTR, NTL);
	}
}
void Lexer::DA2D()
{
	RP = -RS;
	calculateConstant();
}
void Lexer::DA3D()
{
	if (RZ <0)   //Сделал RZ а не RZN(Максим)
	{
		RP = -RP;
	}
	RP -= RS;
	calculateConstant();
}
void Lexer::DA1LOOP()
{

}
void Lexer::error_method(std::string message)
{
	add_error(message);
	RSOS = &Lexer::error_state;
}
void Lexer::addLexem()
{
	switch (RKL)
	{
	case 3:
		UTL[NTL] = lexeme_token{ lexeme_token_class(RKL), RZN };
		NTL++;
		break;
	case 4:
		UTL[NTL] = lexeme_token{ lexeme_token_class(RKL), ROT };
		NTL++;
		break;
	case 1: case 2: case 5: case 6: case 7: case 8: case 9:
		UTL[NTL] = lexeme_token{ lexeme_token_class(RKL), RU };
		NTL++;
		break;
	default:
		UTL[NTL] = lexeme_token{ lexeme_token_class(RKL), RZN };
		NTL++;
		break;
	}
	log_message += "Lexeme added: " + std::to_string(RKL) + '\n';
}
void Lexer::start(std::string filename)
{
	//logging
	std::ofstream ofs;
	ofs.open("log.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();


	std::ifstream infile(filename);
	std::string line;
	while (std::getline(infile, line))
	{
		for (std::string::iterator it = line.begin(); it != line.end(); it++)
		{
			transliterator(*it);
			write_log_file();
			(this->*RSOS)();
			COL++;
		}
		RK = transliterator_token_class::newline;
		write_log_file();
		(this->*RSOS)();
		COL = 1;
		ROW++;
	}
	RK = transliterator_token_class::eof;
	write_log_file();
	(this->*RSOS)();

	if (!error_list.empty())
	{
		print_errors();
	}
	write_log_file();
}
void  Lexer::calculateConstant()
{
	RU = NTO;
	UTO[NTO] = RCH * pow(10, RP);
	NTO++;
	//addLexem();
}

int init_vector(char c)
{
	//m_init_vector = {
	//	0, //a
	//	0, //b
	//	0, //c
	//	0, //d
	//	1, //e
	//	3, //f
	//	5, //g
	//	0,
	//	11, //i
	//	0, 0,
	//	12, //l
	//	0,
	//	14, //n
	//	0,
	//	0, //p
	//	0,
	//	17, //r
	//	23, //s
	//	26, //t
	//	0, 0, 0, 0, 0, 0
	//};
	switch (c)
	{
	case 'e':
		return 1;
		break;
	case 'f':
		return 3;
	case 'g':
		return 5;
	case 'i':
		return 11;
	case 'l':
		return 12;
	case 'n':
		return 14;
	case 'r':
		return 17;
	case 's':
		return 23;
	case 't':
		return 26;
	case 'w':
		return 100;
	default:
		return 0;
		break;
	}
}

void Lexer::transliterator(char c)
{
	if (isdigit(c))
	{
		RZN = c - '0';
		RK = transliterator_token_class::digit;
		return;
	}
	if (isalpha(c))
	{
		c = toupper(c);
		RZN = c - 'A' + 1;
		RK = transliterator_token_class::letter;
		return;
	}
	switch (c)
	{
	case '+':
		RZN = 1;
		RK = transliterator_token_class::arithmetic;
		break;
	case '-':
		RZN = 2;
		RK = transliterator_token_class::arithmetic;
		break;
	case '*':
		RZN = 3;
		RK = transliterator_token_class::arithmetic;
		break;
	case '/':
		RZN = 4;
		RK = transliterator_token_class::arithmetic;
		break;
	case '%':
		RZN = 5;
		RK = transliterator_token_class::arithmetic;
		break;
	case '=':
		RZN = 1;
		ROT = 1;
		RK = transliterator_token_class::relationship;
		break;
	case '<':
		RZN = 2;
		ROT = 2;
		RK = transliterator_token_class::relationship;
		break;
	case '>':
		RZN = 3;
		ROT = 3;
		RK = transliterator_token_class::relationship;
		break;
	case '(':
		RZN = 0;
		RK = transliterator_token_class::left_par;
		break;
	case ')':
		RZN = 0;
		RK = transliterator_token_class::right_par;
		break;
	case '.':
		RZN = 0;
		RK = transliterator_token_class::dot;
		break;
	case ' ':
		RZN = 0;
		RK = transliterator_token_class::CR;
		break;

	default:
		RK = transliterator_token_class::error;
		break;
	}
}

void Lexer::write_log_file()
{
	std::ofstream log_file("log.txt", std::ios_base::app);
	log_file << "NTO: "<<NTO<<std::endl;
	log_file << "NTL: " << NTL << std::endl;
	log_file << "RCH: " << RCH << std::endl;
	log_file << "RZ: " << RZ << std::endl;
	log_file << "RP: " << RP << std::endl;
	log_file << "RS: " << RS << std::endl;
	log_file << "RKL: " << RKL << std::endl;
	log_file << "ROT: " << ROT << std::endl;
	log_file << "RZN: " << RZN << std::endl;
	log_file << "ROB: " << ROB << std::endl;
	log_file << "RK: " << RK << std::endl;
	log_file << "RSTR: " << RSTR << std::endl;
	log_file << "RU: " << RU << std::endl;
	log_file << log_message;
	log_file << "---------------------------------------"<< std::endl;
	log_file.close();
	log_message = "";
}

std::string Lexer::lexeme_list_str()
{
	std::string str;
	for (int i = 0; i < NTL; i++)
	{
		str.append(arr_lexemes[(UTL[i].m_class)]);
		str.push_back(' ');
		str.append(std::to_string(UTL[i].m_value));
		str.push_back('\n');
	}
	return str;

}

std::string Lexer::get_constants()
{
	std::string str;
	for (int i = 278; i < NTO; i++)
	{
		str += std::to_string(UTO[i]) +"\n";
	}
	return str;
}


std::string Lexer::format_lexeme(lexeme_token tkn) const
{
	std::string str;
	char digit;
	char letter;
	std::vector<std::string> arr_arithmetic{ "", "+", "-", "*", "/", "%" };
	std::vector<std::string> arr_relationship{ "", "=", "<", ">", "<>", "<=", ">="  };
	switch (tkn.m_class)
	{
	case Lexer::label:
		return std::to_string(tkn.m_value);
		break;
	case Lexer::identifier:
		if (tkn.m_value < 278)
		{
			letter = (tkn.m_value % 26) + 'A' - 1;
			digit = tkn.m_value / 26 - 1;
			str.push_back(letter);
			if (digit >= 0)
			{
				str.push_back(digit+'0');
			}
			return str;
		}
		else
		{
			return "cnst";
		}
		break;
	case Lexer::arithmetic_operation:
		return arr_arithmetic[tkn.m_value];
		break;
	case Lexer::relationship_operation:
		return arr_relationship[tkn.m_value];
		break;
	case Lexer::end_of_loop:
		letter = (tkn.m_value % 26) + 'A' - 1;
		digit = tkn.m_value / 26 - 1;
		str.push_back(letter);
		if (digit >= 0)
		{
			str.push_back(digit + '0');
		}
		return str;
		break;
	case Lexer::assignment:
		letter = (tkn.m_value % 26) + 'A' - 1;
		digit = tkn.m_value / 26 - 1;
		str.push_back(letter);
		if (digit >= 0)
		{
			str.push_back(digit + '0');
		}
		return str;
		break;
	case Lexer::FOR:
		letter = (tkn.m_value % 26) + 'A' - 1;
		digit = tkn.m_value / 26 - 1;
		str.push_back(letter);
		if (digit >= 0)
		{
			str.push_back(digit + '0');
		}
		return str;
		break;
	case Lexer::transfer:
		return std::to_string(tkn.m_value);
		break;
	case Lexer::transfer_sub:
		return std::to_string(tkn.m_value);
		break;
	case Lexer::left_parenthesis:
		return "";
		break;
	case Lexer::right_parenthesis:
		return "";
		break;
	case Lexer::IF:
		return "";
		break;
	case Lexer::RETURN:
		return "";
		break;
	case Lexer::END:
		return "";
		break;
	case Lexer::TO:
		return "";
		break;
	case Lexer::STEP:
		return "";
		break;
	case Lexer::REM:
		return "";
		break;
	case Lexer::ERROR_LEXEME:
		return "";
		break;
	case Lexer::END_OF_FILE:
		return "";
		break;
	case Lexer::LAST_LEXEME_TOKEN_CLASS:
		return "";
		break;
	default:
		break;
	}
}


std::ostream& operator<<(std::ostream& out, const Lexer& lexer)
{
	out << "Lexeme list:" << std::endl;
	for (int i = 0; i < 25; i++)
	{
		out << '_';
	}
	out << std::endl;
	for (int i = 0; i < lexer.NTL; i++)
	{
			out << '|';
			out << std::setw(5) << i;
			out << '|';
			out << std::setw(25) << arr_lexemes[lexer.UTL[i].m_class];
			out << '|';
			out << std::setw(15) << lexer.format_lexeme(lexer.UTL[i]);
			out << '|';
			out << std::endl;
	}
	out << "Constants list:" << std::endl;
	for (int i = 278; i < lexer.NTO; i++)
	{
		out<< lexer.UTO[i] << std::endl;
	}
	out << "Labels list:" << std::endl;
	out << lexer.UTS;
	return out;
}

void Lexer::add_error(std::string message)
{
	error_list.push_back(LexerError(message, ROW, COL));

}

void Lexer::print_errors() const
{
	std::cout << "Errors:" << std::endl;
	for (std::vector<LexerError>::const_iterator i = error_list.begin(); i != error_list.end(); i++)
	{
		std::cout << *i<<std::endl;
	}
}