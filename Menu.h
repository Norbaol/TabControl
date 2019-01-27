#pragma once
#ifndef MENU_H
#define MENU_H

class MenuItem
{
public:
	MenuItem();
	~MenuItem();
	virtual void SetPrice(const int);
	int GetPrice();
	virtual CString AskConfirmation() = 0;
private:
	int Price;

};

class FoodItem : public MenuItem
{
public:
	FoodItem();
	~FoodItem();
	void SetLVofDone(const int);
	wchar_t* GetLVofDone();
	virtual CString AskConfirmation() = 0;

private:
	int LVofDone;
};

class Hamburger : public FoodItem
{
public:
	Hamburger();
	~Hamburger();
	void SetOnionState(const bool);
	void SetTomatoState(const bool);
	void SetLettuceState(const bool);
	wchar_t* GetOnionState();
	wchar_t* GetTomatoState();
	wchar_t* GetLettuceState();
	CString AskConfirmation();

private:
	bool onion;
	bool tomato;
	bool lettuce;
};

class Steak : public FoodItem
{
public:
	Steak();
	~Steak();
	CString AskConfirmation();

private:
};

class DrinkItem : public MenuItem
{
public:
	DrinkItem();
	~DrinkItem();
	void SetTypeOfDrink(const int);
	virtual wchar_t* GetTypeofDrink();
	virtual CString AskConfirmation() = 0;

protected:
	int TypeOfDrink;
};

class Soda : public DrinkItem
{
public:
	Soda();
	~Soda();
	CString AskConfirmation();

private:
};

class Beer : public DrinkItem
{
public:
	Beer();
	~Beer();
	void SetPrice(const int);
	void SetLiofBeer(const int);
	wchar_t* GetTypeofDrink();
	wchar_t* GetLiofBeer();
	CString AskConfirmation();

private:
	int Li;
};
#endif