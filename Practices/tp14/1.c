#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

typedef enum ExpT
{
	EXP_CONSTANT,
	EXP_PLUS,
	EXP_MINUS,
	EXP_MULT,
	EXP_DIV,
	EXP_SIN,
	EXP_COS,
	EXP_TAN,
	EXP_VARIABLE
} ExpType;

typedef struct Exp_str {
	ExpType tipo;
	union {
		double value; // constants
		struct
		{
			struct Exp_str *Arg1, *Arg2; // binarias
		} binary;
		struct
		{
			struct Exp_str *Arg1; // unarias
		}unary;
	} args;
} *Exp;


// Imprima la expresión en forma legible
void PrintEXP(Exp expr);

// Evalúe la expresión, en el valor de la variable X
double Evaluate(Exp expr, double X);

// Libere todos los recursos asociados a expr.
void Destroy(Exp expr);

// Cree y retorne una expresión de variable
Exp CreateVarEXP();

// Cree y retorne una expresión constante
Exp CreateConstEXP(double value);

// Cree y retorne una expresión unaria
Exp CreateUnaryEXP(ExpType type, Exp expr1);

// Cree y retorne una expresión binaria
Exp CreateBinaryEXP(ExpType type, Exp expr1, Exp expr2);

// Cree y retorne un clon de la expresión recibida
Exp CloneEXP(Exp e);

// Calcule la expresión derivada analítica de la expresión
Exp Derivate(Exp expr);


int main(void)
{
	// rama derecha:
	Exp x1 = CreateVarEXP();
	Exp c1 = CreateConstEXP(2);
	Exp sum1 = CreateBinaryEXP(EXP_PLUS, c1, x1);
	Exp div1 = CreateBinaryEXP(EXP_DIV, x1, sum1);
	Exp COS1 = CreateUnaryEXP(EXP_COS, div1);
	Exp c2 = CreateConstEXP(3);
	Exp MULT1 = CreateBinaryEXP(EXP_MULT, c2, COS1);
	Exp sum2 = CreateBinaryEXP(EXP_PLUS, c1, MULT1);

	//rama izquierda
	Exp MULT2 = CreateBinaryEXP(EXP_MULT, c2, x1);
	Exp c3 = CreateConstEXP(4);
	Exp sum3 = CreateBinaryEXP(EXP_PLUS, MULT2, c3);
	Exp SIN = CreateUnaryEXP(EXP_SIN, sum3);
	Exp div2 = CreateBinaryEXP(EXP_DIV, SIN, sum2);

	PrintEXP(div2);
	puts("\n");
	puts("");
	int i;
	for (i = 0; i < 1.0/0.01; i++)
	{
		printf("%lf\n", Evaluate(div2, i));
		//printf("%d\n", i);
	}
	
	div2 = Derivate (div2);
	PrintEXP(div2);
	puts("\n");
	
	for (i = 0; i < 1.0/0.01; i++)
	{
		printf("%.3lf\n", Evaluate(div2, i));
		//printf("%d\n", i);
	}
	Destroy(div2);
	return 0;
}
void PrintEXP(Exp expr)
{
	switch (expr->tipo)
	{
	case EXP_CONSTANT:
		printf("%.1lf", expr->args.value);
		break;
	case EXP_PLUS:
		PrintEXP(expr->args.binary.Arg1);
		printf("+");
		PrintEXP(expr->args.binary.Arg2);
		break;
	case EXP_MINUS:
		PrintEXP(expr->args.binary.Arg1);
		printf("-");
		PrintEXP(expr->args.binary.Arg2);
		break;
	case EXP_MULT:
		printf("(");
		PrintEXP(expr->args.binary.Arg1);
		printf(")");
		printf("*");
		printf("(");
		PrintEXP(expr->args.binary.Arg2);
		printf(")");
		break;
	case EXP_DIV:
		printf("(");
		PrintEXP(expr->args.binary.Arg1);
		printf(")");
		printf("/");
		printf("(");
		PrintEXP(expr->args.binary.Arg2);
		printf(")");
		break;
	case EXP_SIN:
		printf("sin(");
		PrintEXP(expr->args.unary.Arg1);
		printf(")");
		break;
	case EXP_COS:
		printf("cos(");
		PrintEXP(expr->args.unary.Arg1);
		printf(")");
		break;
	case EXP_TAN:
		printf("tan(");
		PrintEXP(expr->args.unary.Arg1);
		printf(")");
		break;
	case EXP_VARIABLE:
		printf("x");
		break;
	}
}

double Evaluate(Exp expr, double X)
{
	switch (expr->tipo)
	{
	case EXP_CONSTANT:
		return (expr->args.value);
		break;
	case EXP_PLUS:
		return Evaluate(expr->args.binary.Arg1, X) + Evaluate(expr->args.binary.Arg2, X);
		break;
	case EXP_MINUS:
		return Evaluate(expr->args.binary.Arg1, X) - Evaluate(expr->args.binary.Arg2, X);
		break;
	case EXP_MULT:
		return Evaluate(expr->args.binary.Arg1, X) * Evaluate(expr->args.binary.Arg2, X);
		break;
	case EXP_DIV:
		return Evaluate(expr->args.binary.Arg1, X) / Evaluate(expr->args.binary.Arg2, X);
		break;
	case EXP_SIN:
		return sin(Evaluate(expr->args.unary.Arg1, X));
		break;
	case EXP_COS:
		return cos(Evaluate(expr->args.unary.Arg1, X));
		break;
	case EXP_TAN:
		return tan(Evaluate(expr->args.unary.Arg1, X));
		break;
	case EXP_VARIABLE:
		return X;
		break;
	}
}

void Destroy(Exp expr)
{
		switch (expr->tipo)
	{
	case EXP_CONSTANT:
		free(expr);
		break;
	case EXP_PLUS:
		Destroy(expr->args.binary.Arg1);
		Destroy(expr->args.binary.Arg2);
		free(expr);
		break;
	case EXP_MINUS:
		Destroy(expr->args.binary.Arg1);
		Destroy(expr->args.binary.Arg2);
		free(expr);
		break;
	case EXP_MULT:
		Destroy(expr->args.binary.Arg1);
		Destroy(expr->args.binary.Arg2);
		free(expr);
		break;
	case EXP_DIV:
		Destroy(expr->args.binary.Arg1);
		Destroy(expr->args.binary.Arg2);
		free(expr);
		break;
	case EXP_SIN:
		Destroy(expr->args.binary.Arg1);
		free(expr);
		break;
	case EXP_COS:
		Destroy(expr->args.binary.Arg1);
		free(expr);
		break;
	case EXP_TAN:
		Destroy(expr->args.binary.Arg1);
		free(expr);
		break;
	case EXP_VARIABLE:
		free(expr);
		break;
	}
}

Exp CreateVarEXP()
{
	Exp var = (Exp) malloc(sizeof(Exp));
	assert(var);
	var->tipo = EXP_VARIABLE;
	return var;
}

Exp CreateConstEXP(double value)
{
	Exp var = (Exp) malloc(sizeof(Exp));
	assert(var);
	var->tipo = EXP_CONSTANT;
	var->args.value = value;
	return var;
}

Exp CreateUnaryEXP(ExpType type, Exp expr1)
{
	Exp var = (Exp) malloc(sizeof(Exp));
	assert(var);
	var->tipo = type;
	var->args.unary.Arg1 = expr1;
	return var;
}

Exp CreateBinaryEXP(ExpType type, Exp expr1, Exp expr2)
{
	Exp var = (Exp) malloc(sizeof(Exp));
	assert(var);
	var->tipo = type;
	var->args.binary.Arg1 = expr1;
	var->args.binary.Arg2 = expr2;
	return var;
}

Exp CloneEXP(Exp e)
{
	if (e == NULL)
		return e;
	Exp clon = (Exp) malloc(sizeof(Exp));
	clon->tipo = e->tipo;
	if (clon->tipo == EXP_CONSTANT)
	{
		clon->args.value = e->args.value;
		return clon;
	}
	else if (clon->tipo >= EXP_PLUS && clon->tipo <= EXP_DIV)
	{
		clon->args.binary.Arg1 = CloneEXP(e->args.binary.Arg1);
		clon->args.binary.Arg2 = CloneEXP(e->args.binary.Arg2);
		return clon;
	}
	else if (clon->tipo >= EXP_SIN && clon->tipo <= EXP_TAN)
	{
		clon->args.unary.Arg1 = CloneEXP(e->args.unary.Arg1);
		return clon;
	}
	else if (clon->tipo ==  EXP_VARIABLE)
		return clon;
	else
		return NULL;
}

Exp Derivate(Exp expr)
{
	switch (expr->tipo)
	{
	case EXP_CONSTANT:
		return CreateConstEXP(0.0);
		break;
	case EXP_PLUS:
		return CreateBinaryEXP(EXP_PLUS, Derivate (expr->args.binary.Arg1), Derivate (expr->args.binary.Arg2));
		break;
	case EXP_MINUS:
		return CreateBinaryEXP(EXP_MINUS, Derivate (expr->args.binary.Arg1), Derivate (expr->args.binary.Arg2));;
		break;
	case EXP_MULT:
		return CreateBinaryEXP(EXP_PLUS,
									 CreateBinaryEXP(EXP_MULT, CloneEXP(expr->args.binary.Arg1), Derivate (expr->args.binary.Arg2)),
									 CreateBinaryEXP(EXP_MULT, CloneEXP(expr->args.binary.Arg2), Derivate (expr->args.binary.Arg1))
									 );
		break;
	case EXP_DIV:
		return CreateBinaryEXP(EXP_DIV, 
									CreateBinaryEXP(EXP_MINUS, CreateBinaryEXP(EXP_MULT, 
																	CloneEXP(expr->args.binary.Arg2), Derivate (expr->args.binary.Arg1)),
																	CreateBinaryEXP(EXP_MULT, CloneEXP(expr->args.binary.Arg1), Derivate (expr->args.binary.Arg2))
													),
									CreateBinaryEXP(EXP_MULT, CloneEXP(expr->args.binary.Arg2), CloneEXP(expr->args.binary.Arg2)));
		break;
	case EXP_SIN:
		return CreateBinaryEXP(EXP_MULT, Derivate(expr->args.unary.Arg1), CreateUnaryEXP(EXP_COS, CloneEXP(expr->args.unary.Arg1)));
		break;
	case EXP_COS:
		return CreateBinaryEXP(EXP_MULT,
								CreateConstEXP(-1.0),
								CreateBinaryEXP(EXP_MULT,
													CreateUnaryEXP(EXP_SIN,
																	CloneEXP(expr->args.unary.Arg1)
																	),
													Derivate(expr->args.unary.Arg1))
							  );
		break;
	case EXP_TAN:
		return Derivate(CreateBinaryEXP(EXP_DIV, 
										CreateUnaryEXP(EXP_SIN, CloneEXP(expr->args.unary.Arg1)), 
										CreateUnaryEXP(EXP_COS, CloneEXP(expr->args.unary.Arg1)))
						);
		break;
	case EXP_VARIABLE:
		return CreateConstEXP(1.0);
		break;
	}
}

