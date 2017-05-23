/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 193 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* yacc.cpp
* C++ source file generated from yacc.y.
* 
* Date: 04/23/16
* Time: 11:17:54
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\yacc.y"



#line 42 "yacc.cpp"
// repeated because of possible precompiled header
#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\yacc.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
#line 14 ".\\yacc.y"

	// place any extra initialisation code here

#line 66 "yacc.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 19 ".\\yacc.y"

	// place any extra cleanup code here

#line 80 "yacc.cpp"
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 32 ".\\yacc.y"
printf("%f\n", yyattribute(2 - 3));
#line 190 "yacc.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 37 ".\\yacc.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3) + yyattribute(3 - 3);
#line 203 "yacc.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 38 ".\\yacc.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3) - yyattribute(3 - 3);
#line 216 "yacc.cpp"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 41 ".\\yacc.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3) * yyattribute(3 - 3);
#line 229 "yacc.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 42 ".\\yacc.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3) / yyattribute(3 - 3);
#line 242 "yacc.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 43 ".\\yacc.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 255 "yacc.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 45 ".\\yacc.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 3);
#line 268 "yacc.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 48 ".\\yacc.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = 0.0; 
#line 281 "yacc.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 49 ".\\yacc.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = 1.0; 
#line 294 "yacc.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 50 ".\\yacc.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = 2.0; 
#line 307 "yacc.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 51 ".\\yacc.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = 3.0; 
#line 320 "yacc.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 52 ".\\yacc.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = 4.0; 
#line 333 "yacc.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 53 ".\\yacc.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = 5.0; 
#line 346 "yacc.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 54 ".\\yacc.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = 6.0; 
#line 359 "yacc.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 55 ".\\yacc.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = 7.0; 
#line 372 "yacc.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 56 ".\\yacc.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = 8.0; 
#line 385 "yacc.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 57 ".\\yacc.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = 9.0; 
#line 398 "yacc.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "\'\\n\'", 10 },
		{ "\'(\'", 40 },
		{ "\')\'", 41 },
		{ "\'*\'", 42 },
		{ "\'+\'", 43 },
		{ "\'-\'", 45 },
		{ "\'/\'", 47 },
		{ "\'0\'", 48 },
		{ "\'1\'", 49 },
		{ "\'2\'", 50 },
		{ "\'3\'", 51 },
		{ "\'4\'", 52 },
		{ "\'5\'", 53 },
		{ "\'6\'", 54 },
		{ "\'7\'", 55 },
		{ "\'8\'", 56 },
		{ "\'9\'", 57 },
		{ "error", 256 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: lines",
		"lines: lines expr \'\\n\'",
		"lines: lines \'\\n\'",
		"lines:",
		"expr: expr \'+\' term",
		"expr: expr \'-\' term",
		"expr: term",
		"term: term \'*\' factor",
		"term: term \'/\' factor",
		"term: factor",
		"factor: \'(\' expr \')\'",
		"factor: DIGIT",
		"DIGIT: \'0\'",
		"DIGIT: \'1\'",
		"DIGIT: \'2\'",
		"DIGIT: \'3\'",
		"DIGIT: \'4\'",
		"DIGIT: \'5\'",
		"DIGIT: \'6\'",
		"DIGIT: \'7\'",
		"DIGIT: \'8\'",
		"DIGIT: \'9\'"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 3, 0 },
		{ 1, 2, -1 },
		{ 1, 0, -1 },
		{ 2, 3, 1 },
		{ 2, 3, 2 },
		{ 2, 1, -1 },
		{ 3, 3, 3 },
		{ 3, 3, 4 },
		{ 3, 1, 5 },
		{ 4, 3, 6 },
		{ 4, 1, -1 },
		{ 5, 1, 7 },
		{ 5, 1, 8 },
		{ 5, 1, 9 },
		{ 5, 1, 10 },
		{ 5, 1, 11 },
		{ 5, 1, 12 },
		{ 5, 1, 13 },
		{ 5, 1, 14 },
		{ 5, 1, 15 },
		{ 5, 1, 16 }
	};
	yyreduction = reduction;

	yytokenaction_size = 33;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 23, YYAT_SHIFT, 3 },
		{ 14, YYAT_SHIFT, 19 },
		{ 18, YYAT_SHIFT, 24 },
		{ -1, YYAT_ERROR, 0 },
		{ 18, YYAT_SHIFT, 20 },
		{ -1, YYAT_ERROR, 0 },
		{ 18, YYAT_SHIFT, 21 },
		{ -1, YYAT_ERROR, 0 },
		{ 23, YYAT_SHIFT, 4 },
		{ 23, YYAT_SHIFT, 5 },
		{ 23, YYAT_SHIFT, 6 },
		{ 23, YYAT_SHIFT, 7 },
		{ 23, YYAT_SHIFT, 8 },
		{ 23, YYAT_SHIFT, 9 },
		{ 23, YYAT_SHIFT, 10 },
		{ 23, YYAT_SHIFT, 11 },
		{ 23, YYAT_SHIFT, 12 },
		{ 23, YYAT_SHIFT, 13 },
		{ 1, YYAT_ACCEPT, 0 },
		{ 26, YYAT_SHIFT, 22 },
		{ 25, YYAT_SHIFT, 22 },
		{ 15, YYAT_SHIFT, 22 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 26, YYAT_SHIFT, 23 },
		{ 25, YYAT_SHIFT, 23 },
		{ 15, YYAT_SHIFT, 23 },
		{ -1, YYAT_ERROR, 0 },
		{ 1, YYAT_SHIFT, 2 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 14, YYAT_ERROR, 0 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 18, 1, YYAT_DEFAULT, 23 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_DEFAULT, 23 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ -9, 1, YYAT_DEFAULT, 18 },
		{ -21, 1, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ -39, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_DEFAULT, 23 },
		{ 0, 0, YYAT_DEFAULT, 23 },
		{ 0, 0, YYAT_DEFAULT, 23 },
		{ -40, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ -22, 1, YYAT_REDUCE, 4 },
		{ -23, 1, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 0, 0, YYAT_REDUCE, 8 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 10;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 23, 28 },
		{ 23, 17 },
		{ 21, 26 },
		{ 21, 16 },
		{ 3, 18 },
		{ 3, 15 },
		{ 22, 27 },
		{ 20, 25 },
		{ 1, 14 },
		{ 0, 1 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 8, -1 },
		{ 6, 3 },
		{ 0, -1 },
		{ 2, 21 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 4, 21 },
		{ -1, 23 },
		{ 2, 23 },
		{ -4, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 59 ".\\yacc.y"






int YYPARSERNAME::yygettoken()
{
	return getchar();
}
int main()
{
//create a lexer, and call the lex function.
//it will read from stdin and parser the tokens.
	int n = 1;
	
	YYPARSERNAME parser;
	if (parser.yycreate()) 
	{
		n = parser.yyparse();
	}
	return n;
}
