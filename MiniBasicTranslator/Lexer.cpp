#include "Lexer.h"
#include <fstream>
#include <string>
#include <math.h>
#include <ctype.h>
#include <iomanip>

std::vector<std::string> arr_lexemes = { "", "LABEL", "ID", "ARITHMETIC",
"RELATIONSHIP", "NEXT", "LET", "FOR", "GOTO",
"GOSUB", "(", ")", "IF", "RETURN", "END", "TO", "STEP", "REM", "WHILE", "ENDW",
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
		{ 'D', 0, &Lexer::W1a },
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
		{ 'O', 0, &Lexer::A2u },
		{ 'H', 0, &Lexer::B1d },
		{ 'I', 0, &Lexer::B1d },
		{ 'L', 0, &Lexer::B1d },
		{ 'E', 0, &Lexer::A2v }
		

	};
	UTO = new float[500];
	for (int i = 0; i < 100; i++)
	{
		UTO[i] = 0;
	}
	NTO = 278;
	UTL = new lexeme_token[500];
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
		error_method("Label is expected");
		break;
	case Lexer::digit:
		E2a();
		break;
	case Lexer::arithmetic:
		error_method("Label is expected");
		break;
	case Lexer::relationship:
		error_method("Label is expected");
		break;
	case Lexer::left_par:
		error_method("Label is expected");
		break;
	case Lexer::right_par:
		error_method("Label is expected");
		break;
	case Lexer::dot:
		error_method("Label is expected");
		break;
	case Lexer::CR:
		break;
	case Lexer::newline:
		break;
	case Lexer::eof:
		EXIT1();
		break;
	case Lexer::error:
		error_method("Invalid character");
		break;
	case Lexer::last_transliterator_token_class:
		error_method("Something went very wrong");
		break;
	default:
		error_method("Something went very wrong");
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
		error_method("Invalid character");
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
		error_method("Not a keyword");
		break;
	case Lexer::arithmetic:
		error_method("Not a keyword");
		break;
	case Lexer::relationship:
		error_method("Not a keyword");
		break;
	case Lexer::left_par:
		error_method("Not a keyword");
		break;
	case Lexer::right_par:
		error_method("Not a keyword");
		break;
	case Lexer::dot:
		error_method("Not a keyword");
		break;
	case Lexer::CR:
		RSOS = &Lexer::B1;
		break;
	case Lexer::newline:
		error_method("Not a keyword");
		break;
	case Lexer::eof:
		error_method("Not a keyword");
		break;
	case Lexer::error:
		error_method("Invalid character");
		break;
	case Lexer::last_transliterator_token_class:
		error_method("Not a keyword");
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
		error_method("Unexpected character in variable");
		break;
	case Lexer::arithmetic:
		error_method("Unexpected character in variable");
		break;
	case Lexer::relationship:
		error_method("Unexpected character in variable");
		break;
	case Lexer::left_par:
		error_method("Unexpected character in variable");
		break;
	case Lexer::right_par:
		error_method("Unexpected character in variable");
		break;
	case Lexer::dot:
		error_method("Unexpected character in variable");
		break;
	case Lexer::CR:
		RSOS = &Lexer::C1;
		break;
	case Lexer::newline:
		error_method("Variable is expected");
		break;
	case Lexer::eof:
		EXIT3();
		break;
	case Lexer::error:
		error_method("Invalid character");
		break;
	case Lexer::last_transliterator_token_class:
		error_method("Not a variable");
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
		error_method("Unexpected character: dot cannot go after variable");
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
		error_method("Invalid character");
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
		error_method("Unexpected character: real number cannot have two dots");
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
		error_method("Unexpected character: exponent cannot contain a letter");
		break;
	case Lexer::digit:
		D5a();
		break;
	case Lexer::arithmetic:
		D4a();
		break;
	case Lexer::relationship:
		error_method("Unexpected character: exponent cannot contain a relationship");
		break;
	case Lexer::left_par:
		error_method("Unexpected character: exponent cannot contain parentheses");
		break;
	case Lexer::right_par:
		error_method("Unexpected character: exponent cannot contain parentheses");
		break;
	case Lexer::dot:
		error_method("Unexpected character: exponent cannot contain dots");
		break;
	case Lexer::CR:
		RSOS = &Lexer::D3;
		break;
	case Lexer::newline:
		error_method("Invalid exponent");
		break;
	case Lexer::eof:
		error_method("Invalid exponent");
		break;
	case Lexer::error:
		error_method("Invalid character");
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
		error_method("Unexpected character: exponent cannot contain a letter");
		break;
	case Lexer::digit:
		D5b();
		break;
	case Lexer::arithmetic:
		error_method("Unexpected character: exponent cannot contain two operation symbols");
		break;
	case Lexer::relationship:
		error_method("Unexpected character: exponent cannot contain a relationship");
		break;
	case Lexer::left_par:
		error_method("Unexpected character: exponent cannot contain parentheses");
		break;
	case Lexer::right_par:
		error_method("Unexpected character: exponent cannot contain parentheses");
		break;
	case Lexer::dot:
		error_method("Unexpected character: exponent cannot contain dots");
		break;
	case Lexer::CR:
		RSOS = &Lexer::D4;
		break;
	case Lexer::newline:
		error_method("Invalid exponent");
		break;
	case Lexer::eof:
		error_method("Invalid exponent");
		break;
	case Lexer::error:
		error_method("Invalid character");
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
		error_method("Unexpected character: exponent cannot contain dots");
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
		error_method("Invalid character");
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
		error_method("Unexpected character: letter cannot go after dot");
		break;
	case Lexer::digit:
		D2b();
		break;
	case Lexer::arithmetic:
		error_method("Unexpected character: arithmetic operation cannot go after dot");
		break;
	case Lexer::relationship:
		error_method("Unexpected character: relationship operation cannot go after dot");
		break;
	case Lexer::left_par:
		error_method("Unexpected character: parenthesis cannot go after dot");
		break;
	case Lexer::right_par:
		error_method("Unexpected character: parenthesis cannot go after dot");
		break;
	case Lexer::dot:
		error_method("Unexpected character: dot cannot go after dot");
		break;
	case Lexer::CR:
		RSOS = &Lexer::D6;
		break;
	case Lexer::newline:
		error_method("Invalid constant");
		break;
	case Lexer::eof:
		error_method("Invalid constant");
		break;
	case Lexer::error:
		error_method("Invalid character");
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
		error_method("Unexpected character in label");
		break;
	case Lexer::digit:
		E2b();
		break;
	case Lexer::arithmetic:
		error_method("Unexpected character in label");
		break;
	case Lexer::relationship:
		error_method("Unexpected character in label");
		break;
	case Lexer::left_par:
		error_method("Unexpected character in label");
		break;
	case Lexer::right_par:
		error_method("Unexpected character in label");
		break;
	case Lexer::dot:
		error_method("Unexpected character in label");
		break;
	case Lexer::CR:
		RSOS = &Lexer::E1;
		break;
	case Lexer::newline:
		error_method("Unexpected character in label");
		break;
	case Lexer::eof:
		error_method("Unexpected character in label");
		break;
	case Lexer::error:
		error_method("Unexpected character in label");
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
		error_method("Unexpected character in label");
		break;
	case Lexer::CR:
		RSOS = &Lexer::E2;
		break;
	case Lexer::newline:
		A1e();
		break;
	case Lexer::eof:
		error_method("Unexpected character in label");
		break;
	case Lexer::error:
		error_method("Unexpected character in label");
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
		error_method("Unexpected character in variable");
		break;
	case Lexer::arithmetic:
		error_method("Unexpected character in variable");
		break;
	case Lexer::relationship:
		error_method("Unexpected character in variable");
		break;
	case Lexer::left_par:
		error_method("Unexpected character in variable");
		break;
	case Lexer::right_par:
		error_method("Unexpected character in variable");
		break;
	case Lexer::dot:
		error_method("Unexpected character in variable");
		break;
	case Lexer::CR:
		RSOS = &Lexer::F1;
		break;
	case Lexer::newline:
		error_method("Unexpected character in variable");
		break;
	case Lexer::eof:
		error_method("Unexpected character in variable");
		break;
	case Lexer::error:
		error_method("Unexpected character in variable");
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
		error_method("Unexpected character in variable");
		break;
	case Lexer::digit:
		F3a();
		break;
	case Lexer::arithmetic:
		error_method("Unexpected character in variable");
		break;
	case Lexer::relationship:
		A2o();
		break;
	case Lexer::left_par:
		error_method("Unexpected character in variable");
		break;
	case Lexer::right_par:
		error_method("Unexpected character in variable");
		break;
	case Lexer::dot:
		error_method("Unexpected character in variable");
		break;
	case Lexer::CR:
		RSOS = &Lexer::F2;
		break;
	case Lexer::newline:
		error_method("Unexpected character in variable");
		break;
	case Lexer::eof:
		error_method("Unexpected character in variable");
		break;
	case Lexer::error:
		error_method("Unexpected character in variable");
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
		error_method("Unexpected character: expected =");
		break;
	case Lexer::digit:
		error_method("Unexpected character: expected =");
		break;
	case Lexer::arithmetic:
		error_method("Unexpected character: expected =");
		break;
	case Lexer::relationship:
		A2o();
		break;
	case Lexer::left_par:
		error_method("Unexpected character: expected =");
		break;
	case Lexer::right_par:
		error_method("Unexpected character: expected =");
		break;
	case Lexer::dot:
		error_method("Unexpected character: expected =");
		break;
	case Lexer::CR:
		RSOS = &Lexer::F3;
		break;
	case Lexer::newline:
		error_method("Unexpected character: expected =");
		break;
	case Lexer::eof:
		error_method("Unexpected character: expected =");
		break;
	case Lexer::error:
		error_method("Unexpected character: expected =");
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
		RSOS = &Lexer::H1;
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

void Lexer::W1()
{
	switch (RK)
	{
	case Lexer::letter:
		if (RZN == 23)
		{
			RKL = ENDW;
			A2b();
			RSOS = &Lexer::A2;
		}
		else
		{
			A2q();
			C2a();
		}
		break;
	case Lexer::digit:
		A2q();
		D1a();
		break;
	case Lexer::arithmetic:
		A2q();
		A2a();
		break;
	case Lexer::relationship:
		A2q();
		H1a();
		break;
	case Lexer::left_par:
		A2q();
		A2h();
		break;
	case Lexer::right_par:
		A2q();
		A3b();
		break;
	case Lexer::dot:
		A2q();
		RSOS = &Lexer::D6;
		break;
	case Lexer::CR:
		A2q();
		RSOS = &Lexer::A2;
		break;
	case Lexer::newline:
		A2q();
		RSOS = &Lexer::A1;
		break;
	case Lexer::eof:
		A2q();
		EXIT1();
		break;
	case Lexer::error:
		error_method("Invalid character");
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
	addLexem();
	RKL = arithmetic_operation;
	addLexem();
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
		error_method("Unexpected character: expected =");
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
			break;
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
		error_method("Invalid relationship operation");
	}
	ROT = new_relationship;
	A2b();
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
void Lexer::A2v()
{
	RKL = lexeme_token_class::WHILE;
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
	addLexem();
	RKL = right_parenthesis;
	addLexem();
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
	if (ROB == 0)
		error_method("Invalid keyword");
	else
		RSOS = &Lexer::B1;
}
void Lexer::B1b()
{
	addLexem();
	ROB = init_vector(RZN - 1);
	if (ROB == 0)
		error_method("Invalid keyword");
	else
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
void Lexer::—1b()
{
	//ÕÂÚ Ú‡ÍÓÈ ÙÛÌÍˆËË
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
	D1a();
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
		break;
	case 2:
		RZ = -1;
		break;
	default:
		error_method("Unexpected character: not + or -");
		break;
	}
	RSOS = &Lexer::D4;
}


void Lexer::D5a( )
{
	RZ = 1;
	RP = RZN;
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
	addLexem();
	ROT = RZN;
	RKL = lexeme_token_class::relationship_operation;
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
		error_method("Invalid keyword");
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
		RSOS = &Lexer::D3;
	}
}
void Lexer::W1a()
{
	RSOS = &Lexer::W1;
}
void Lexer::EXIT1()
{
	//"¬€’Œƒ1:    «‡„ÛÁËÚ¸  ŒÕ≈÷ Ã¿– ≈– ‚ –≈√»—“–  À¿——¿" ◊ÚÓ Ú‡ÍÓÂ  ŒÕ≈÷ Ã¿– ≈–?
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
	if (RKL == lexeme_token_class::label)
	{
		RU = UTS.add(RSTR, NTL);
	}
	else
	{
		if (pos != -1)
		{
			RU = pos;
		}
		else
		{
			RU = UTS.add(RSTR, -1);
		}
	}
	
}
void Lexer::DA2D()
{
	RP = -RS;
	calculateConstant();
}
void Lexer::DA3D()
{
	if (RZ <0)   //—‰ÂÎ‡Î RZ ‡ ÌÂ RZN(Ã‡ÍÒËÏ)
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
			(this->*RSOS)();
			COL++;
			write_tables();
		}
		RK = transliterator_token_class::newline;
		(this->*RSOS)();
		COL = 1;
		ROW++;
	}
	RK = transliterator_token_class::eof;
	(this->*RSOS)();

	if (!error_list.empty())
	{
		print_errors();
	}
	else
	{
		std::cout << "Done" << std::endl;
	}
	write_tables();
}
void  Lexer::calculateConstant()
{
	RU = NTO;
	UTO[NTO] = RCH * pow(10, RP);
	NTO++;
	//addLexem();
}

int Lexer::init_vector(char c)
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
	c = c + 'a';
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
		return 27;
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
	case '^':
		RZN = 5;
		RK = transliterator_token_class::arithmetic;
		break;

	case '=':
		RZN = 1;
		RK = transliterator_token_class::relationship;
		break;
	case '<':
		RZN = 2;
		RK = transliterator_token_class::relationship;
		break;
	case '>':
		RZN = 3;
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

void Lexer::write_tables() const
{
	std::ofstream lexemes_file("_lexemes.txt");
	lexemes_file << "Lexeme list:" << std::endl;
	for (int i = 0; i < 25; i++)
	{
		lexemes_file << '_';
	}
	lexemes_file << std::endl;
	for (int i = 0; i < NTL; i++)
	{
		lexemes_file << '|';
		lexemes_file << std::setw(5) << i;
		lexemes_file << '|';
		lexemes_file << std::setw(25) << arr_lexemes[UTL[i].m_class];
		lexemes_file << '|';
		lexemes_file << std::setw(15) << format_lexeme(UTL[i]);
		lexemes_file << '|';
		lexemes_file << std::endl;
	}
	lexemes_file.close();

	std::ofstream constants_file("_constants.txt");
	constants_file << "Constants list:" << std::endl;
	for (int i = 278; i < NTO; i++)
	{
		constants_file << UTO[i] << std::endl;
	}
	constants_file.close();

	std::ofstream labels_file("_labels.txt");
	labels_file << "Labels list:" << std::endl;
	labels_file << UTS;

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
	std::vector<std::string> arr_arithmetic{ "", "+", "-", "*", "/", "^" };
	std::vector<std::string> arr_relationship{ "", "=", "<", ">", "<>", "<=", ">="  };
	switch (tkn.m_class)
	{
	case lexeme_token_class::label:
		return std::to_string(tkn.m_value);
		break;
	case lexeme_token_class::identifier:
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
	case lexeme_token_class::arithmetic_operation:
		return arr_arithmetic[tkn.m_value];
		break;
	case lexeme_token_class::relationship_operation:
		return arr_relationship[tkn.m_value];
		break;
	case lexeme_token_class::end_of_loop:
		letter = (tkn.m_value % 26) + 'A' - 1;
		digit = tkn.m_value / 26 - 1;
		str.push_back(letter);
		if (digit >= 0)
		{
			str.push_back(digit + '0');
		}
		return str;
		break;
	case lexeme_token_class::assignment:
		letter = (tkn.m_value % 26) + 'A' - 1;
		digit = tkn.m_value / 26 - 1;
		str.push_back(letter);
		if (digit >= 0)
		{
			str.push_back(digit + '0');
		}
		return str;
		break;
	case lexeme_token_class::FOR:
		letter = (tkn.m_value % 26) + 'A' - 1;
		digit = tkn.m_value / 26 - 1;
		str.push_back(letter);
		if (digit >= 0)
		{
			str.push_back(digit + '0');
		}
		return str;
		break;
	case lexeme_token_class::transfer:
		return std::to_string(tkn.m_value);
		break;
	case lexeme_token_class::transfer_sub:
		return std::to_string(tkn.m_value);
		break;
	case lexeme_token_class::left_parenthesis:
		return "";
		break;
	case lexeme_token_class::right_parenthesis:
		return "";
		break;
	case lexeme_token_class::IF:
		return "";
		break;
	case lexeme_token_class::RETURN:
		return "";
		break;
	case lexeme_token_class::END:
		return "";
		break;
	case lexeme_token_class::TO:
		return "";
		break;
	case lexeme_token_class::STEP:
		return "";
		break;
	case lexeme_token_class::REM:
		return "";
		break;
	case lexeme_token_class::WHILE:
		return "";
		break;
	case lexeme_token_class::ENDW:
		return "";
		break;
	case lexeme_token_class::ERROR_LEXEME:
		return "";
		break;
	case lexeme_token_class::END_OF_FILE:
		return "";
		break;
	case lexeme_token_class::LAST_LEXEME_TOKEN_CLASS:
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