#pragma once
#include "Hashtable.h"
#include <iostream>
#include <vector>
class Lexer
{
	enum lexeme_token_class
	{
		label=1, identifier, arithmetic_operation, relationship_operation, end_of_loop, assignment, transfer, transfer_sub, 
		left_parenthesis, right_parenthesis, IF, RETURN, END, TO, STEP, REM, ERROR_LEXEME, END_OF_FILE, LAST_LEXEME_TOKEN_CLASS
	};
	struct lexeme_token
	{
		lexeme_token_class m_class;
		int m_value;
	};
	enum transliterator_token_class
	{
		letter, digit, arithmetic, relationship, left_par, right_par, dot, CR, newline, eof, last_transliterator_token_class
	};
	struct transliterator_token
	{
		transliterator_token_class m_class;
		int m_value;
	};
	struct id
	{
		int m_name;
		float m_value;
	};
	transliterator_token transliterator(char symbol);
	Hashtable TS;
	std::vector<id> TO;
	std::vector<lexeme_token> TL;
	int UTS;
	int UTO;
	int UTL;
	int NTS;
	int NTO;
	int NTL;
	int RCH;
	int RZ;
	int RP;
	int RS;
	int RKL;
	int ROT;
	int RZN;
	int RSOS;
	int ROB;
	int RK;
	std::string RSTR;

	typedef void(Lexer::*lexer_method)(transliterator_token);
	void A1(transliterator_token tkn);
	void A1a(transliterator_token tkn);
	void A1b(transliterator_token tkn);
	void A1c(transliterator_token tkn);
	void A1d(transliterator_token tkn);
	void A1e(transliterator_token tkn);
	void A2(transliterator_token tkn);
	void A2a(transliterator_token tkn);
	void A2b(transliterator_token tkn);
	void A2c(transliterator_token tkn);
	void A2d(transliterator_token tkn);
	void A2e(transliterator_token tkn);
	void A2f(transliterator_token tkn);
	void A2g(transliterator_token tkn);
	void A2h(transliterator_token tkn);
	void A2i(transliterator_token tkn);
	void A2j(transliterator_token tkn);
	void A2k(transliterator_token tkn);
	void A2l(transliterator_token tkn);
	void A2m(transliterator_token tkn);
	void A2n(transliterator_token tkn);
	void A2o(transliterator_token tkn);
	void A2p(transliterator_token tkn);
	void A2q(transliterator_token tkn);
	void A2r(transliterator_token tkn);
	void A2s(transliterator_token tkn);
	void A2t(transliterator_token tkn);
	void A2u(transliterator_token tkn);
	void A3(transliterator_token tkn);
	void A3a(transliterator_token tkn);
	void A3b(transliterator_token tkn);
	void A3c(transliterator_token tkn);
	void A3d(transliterator_token tkn);
	void A3e(transliterator_token tkn);
	void A3f(transliterator_token tkn);
	void A3g(transliterator_token tkn);
	void B1(transliterator_token tkn);
	void B1a(transliterator_token tkn);
	void B1b(transliterator_token tkn);
	void B1c(transliterator_token tkn);
	void B1d(transliterator_token tkn);
	void B1e(transliterator_token tkn);
	void C1(transliterator_token tkn);
	void C1a(transliterator_token tkn);
	void Ñ1b(transliterator_token tkn)
	{
		int a = 5;
		int b = 6;
		a + b;
		printf("hui");
		int c = 1 + 1 * 2;
		c = a + b;
		int h = 1;
		int e = 4;
		int i = 8;
		int l = 8;
	}
	void A1(transliterator_token tkn);
	void A1(transliterator_token tkn);
	void A1(transliterator_token tkn);
	void A1(transliterator_token tkn);
	void A1(transliterator_token tkn);
	void A1(transliterator_token tkn);
	void A1(transliterator_token tkn);
	void A1(transliterator_token tkn);
	void A1(transliterator_token tkn);
	void A1(transliterator_token tkn);
	void A1(transliterator_token tkn);
	void A1(transliterator_token tkn);
	void A1(transliterator_token tkn);
	void A1(transliterator_token tkn);
	void A1(transliterator_token tkn);
	void A1(transliterator_token tkn);
	void A1(transliterator_token tkn);
	void A1(transliterator_token tkn);
	void A1(transliterator_token tkn);
	void A1(transliterator_token tkn);
	void A1(transliterator_token tkn);
	void A1(transliterator_token tkn);
	void A1(transliterator_token tkn);
public:
	Lexer();
	~Lexer();
};

