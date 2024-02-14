#pragma once

enum class TITLE
{
	START = 1,
	EXIT
};

enum class START
{
	CONTINUE = 1,
	BEGIN
};

enum class SAVE
{
	SAVE = 1,
	NOTSAVE
};

enum class JOB
{
	FIGHTER = 1,
	MAGITION,
	THIEF
};

enum class DEST
{
	FIELD = 1,
	SHOP,
	BACK
};

enum class FIELD
{
	GOBLIN = 1,
	ORC,
	ORGER,
	BACK
};

enum class BATTLE
{
	ATTACK = 1,
	RUN
};

enum class CONSUMABLE
{
	REDP = 1,
	ANTI,
	BAND,
	MENTAL,
	RETURN
};

enum class EQUIPRANK
{
	OLD = 1,
	NEW,
	HARD,
	BACK
};

enum class EQUIP
{
	WEAPON = 1,
	ARMOR,
	BACK
};