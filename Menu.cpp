#include "stdafx.h"
#include "afxdialogex.h"
#include "Menu.h"

MenuItem::MenuItem()
{
}

MenuItem::~MenuItem()
{
}

void MenuItem::SetPrice(const int P)
{
	Price = P;
}

int MenuItem::GetPrice()
{
	return Price;
}

FoodItem::FoodItem()
{
}

FoodItem::~FoodItem()
{
}

void FoodItem::SetLVofDone(const int D)
{
	LVofDone = D;
}

wchar_t* FoodItem::GetLVofDone()
{
	switch (LVofDone)
	{
	case 0:
		return L"Rare";
	case 1:
		return L"Medium Rare";
	case 2:
		return L"Medium";
	case 3:
		return L"Medium Well";
	case 4:
		return L"Well Done";
	}
	return NULL;
}

Hamburger::Hamburger()
{
	SetPrice(50);
	onion = FALSE;
	tomato = FALSE;
	lettuce = FALSE;
}

Hamburger::~Hamburger()
{
}

void Hamburger::SetOnionState(const bool Oni)
{
	onion = Oni;
}

void Hamburger::SetTomatoState(const bool Tom)
{
	tomato = Tom;
}

void Hamburger::SetLettuceState(const bool Let)
{
	lettuce = Let;
}

wchar_t * Hamburger::GetOnionState()
{
	if (onion)
		return L"with Onions";
	else
		return L"without Onions";
}

wchar_t * Hamburger::GetTomatoState()
{
	if (tomato)
		return L"with Tomatos";
	else
		return L"without Tomatos";
}

wchar_t * Hamburger::GetLettuceState()
{
	if (lettuce)
		return L"with Lettuce";
	else
		return L"without Lettuce";
}

CString Hamburger::AskConfirmation()
{
	wchar_t *O = L"",//onions
			*T = L"",//tomatos
			*L = L"";//lettuce
	if (!onion)
		O = L"out";
	if (!tomato)
		T = L"out";
	if (!lettuce)
		L = L"out";
	CString ConfirmMassage;
	ConfirmMassage.Format(L"you are about to order a hamburger with the following charasteristics:\n\nLevel of Doneness: %s\nWith%s onions\nWith%s Tomatos\nand With%s Lettuce\n\nConfirm Order?", GetLVofDone(), O, T, L);
	return ConfirmMassage;
}

Steak::Steak()
{
	SetPrice(75);
}

Steak::~Steak()
{
}

CString Steak::AskConfirmation()
{
	CString ConfirmMassage;
	ConfirmMassage.Format(L"you are about to order a %s Steak\n\nConfirm Order?", GetLVofDone());
	return ConfirmMassage;
}

DrinkItem::DrinkItem()
{
}

DrinkItem::~DrinkItem()
{
}

void DrinkItem::SetTypeOfDrink(const int Ty)
{
	TypeOfDrink = Ty;
}

wchar_t * DrinkItem::GetTypeofDrink()
{
	if (TypeOfDrink == 0)
		return L"Soda1";
	else
		return L"Soda2";
}

Soda::Soda()
{
}

Soda::~Soda()
{
}

CString Soda::AskConfirmation()
{
	CString ConfirmMassage;
	ConfirmMassage.Format(L"you are about to order %s\n\nConfirm Order?",GetTypeofDrink());
	return ConfirmMassage;
}

Beer::Beer()
{
}

Beer::~Beer()
{
}

void Beer::SetPrice(const int P)//will recive a price for a liter
{
	switch (Li)
	{
	case 0:
		MenuItem::SetPrice(P*0.3);
		break;
	case 1:
		MenuItem::SetPrice(P*0.5);
		break;
	default:
		MenuItem::SetPrice(P);
		break;
	}
}

void Beer::SetLiofBeer(const int L)
{
	Li = L;
}

wchar_t * Beer::GetTypeofDrink()
{
	if (TypeOfDrink == 2)
	{
		SetPrice(62);
		return L"Beer1";
	}
	else
	{
		SetPrice(58);
		return L"Beer2";
	}
}

wchar_t * Beer::GetLiofBeer()
{
	switch (Li)
	{
	case 0:
		return L"0.330L";
	case 1:
		return L"0.5L";
	case 2:
		return L"1L";
	}
	return NULL;
}

CString Beer::AskConfirmation()
{
	CString ConfirmMassage;
	ConfirmMassage.Format(L"you are about to order %s of %s\n\nConfirm Order?", GetLiofBeer(),GetTypeofDrink());
	return ConfirmMassage;
}
