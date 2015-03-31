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
	enum state
	{
		A1, A2, A3, B1, C1, C2, D1, D2, D3, D4, D5, D6, E1, E2, F1, F2, F3, G1, H1, LAST_STATE
	};
	enum relation
	{ 
		equal, less, more, notequal, lessorequal, moreorequal 
	};
	transliterator_token transliterator(char symbol);
	Hashtable TS;
	std::vector<id> TO;
	std::vector<lexeme_token> TL;
	int UTS;
	int UTO;
	int UTL;
	int NTS;
	int NTO; //Указатель на первый свободный элемент в ТО
	int NTL; //Указатель на первый свободный элемент в ТL
	int RCH; //регистр числа
	int RZ; //регистр знака порядка
	int RP; //регистр порядка
	int RS; //регистр счетчика
	int RKL; //регистр класса лексем
	int ROT; //регистр значения отношения
	int RZN; //регистр значения символа
	int RSOS; //регистр состояния
	int ROB; //регистр обнаружения
	int RK; //регистр значения класса символа
	std::string RSTR; //регистр строки

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
	void С1b(transliterator_token tkn);
	void C2a(transliterator_token tkn);
	void C2b(transliterator_token tkn);
	void C2d(transliterator_token tkn);
	void C2(transliterator_token tkn);
	void D1(transliterator_token tkn);
	void D1a(transliterator_token tkn);
	void D1b(transliterator_token tkn);
	void D1c(transliterator_token tkn);
	void D2(transliterator_token tkn);
	void D2a(transliterator_token tkn);
	void D2b(transliterator_token tkn);
	void D2c(transliterator_token tkn);
	void D3(transliterator_token tkn);
	void D3a(transliterator_token tkn);
	void D4(transliterator_token tkn);
	void D4a(transliterator_token tkn);
	void D5(transliterator_token tkn);
	void D5a(transliterator_token tkn);
	void D5b(transliterator_token tkn);
	void D5c(transliterator_token tkn);
	void D6(transliterator_token tkn);
	void D6a(transliterator_token tkn);
	void E1(transliterator_token tkn);
	void E1a(transliterator_token tkn);
	void E1b(transliterator_token tkn);
	void E2(transliterator_token tkn);
	void E2a(transliterator_token tkn);
	void E2b(transliterator_token tkn);
	void E2c(transliterator_token tkn);
	void F1(transliterator_token tkn);
	void F1a(transliterator_token tkn);
	void F1b(transliterator_token tkn);
	void F2(transliterator_token tkn);
	void F2a(transliterator_token tkn);
	void F2b(transliterator_token tkn);
	void F3(transliterator_token tkn);
	void F3a(transliterator_token tkn);
	void G1(transliterator_token tkn);
	void G1a(transliterator_token tkn);
	void H1(transliterator_token tkn);
	void H1a(transliterator_token tkn);
	void H1b(transliterator_token tkn);
	void H1c(transliterator_token tkn);
	void H1d(transliterator_token tkn);
	void H1e(transliterator_token tkn);
	void H1f(transliterator_token tkn);
	void M1(transliterator_token tkn);
	void M2(transliterator_token tkn);
	void M3(transliterator_token tkn);
	void H1a(transliterator_token tkn);
	void EXIT1(transliterator_token tkn);
	void EXIT2(transliterator_token tkn);
	void EXIT3(transliterator_token tkn);
	void EXIT4(transliterator_token tkn);
	void EXIT5(transliterator_token tkn);
	void EXIT6(transliterator_token tkn);
	void DA1D(transliterator_token tkn);
	void DA1E(transliterator_token tkn);
	void DA2D(transliterator_token tkn);
	void DA3D(transliterator_token tkn);
	void DA1LOOP(transliterator_token tkn);
	void addLexem();
public:
	Lexer();
	~Lexer();
};

