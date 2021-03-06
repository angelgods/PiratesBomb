#pragma once
#ifndef Collision

static const short CATEGORY_PLAYER = 0x0001;
static const short CATEGORY_MONSTER = 0x0002;
static const short CATEGORY_SCENERY = 0x0004;
static const short CATEGORY_BOSS = 0x0008;
static const short CATEGORY_GROUND = 0x0010;
static const short CATEGORY_ITEM = 0x0020;
static const short CATEGORY_BOMB = 0x0040;
static const short CATEGORY_BULLET = 0x0080;
static const short CATEGORY_BULLET_BOSS = 0x0100;

static const short MASK_PLAYER = CATEGORY_GROUND | CATEGORY_SCENERY| CATEGORY_BOMB|CATEGORY_MONSTER|CATEGORY_BOSS| CATEGORY_BULLET_BOSS|CATEGORY_ITEM;
static const short MASK_BOMB = CATEGORY_GROUND | CATEGORY_SCENERY|CATEGORY_BOMB| CATEGORY_PLAYER|CATEGORY_MONSTER| CATEGORY_BULLET|CATEGORY_BOSS;
static const short MASK_GROUND = CATEGORY_BOMB | CATEGORY_PLAYER| CATEGORY_BULLET| CATEGORY_BULLET_BOSS|CATEGORY_ITEM;
static const short MASK_MONSTER = CATEGORY_BOMB|CATEGORY_PLAYER| CATEGORY_BULLET|CATEGORY_MONSTER|CATEGORY_BOSS;
static const short MASK_BULLET = CATEGORY_GROUND | CATEGORY_SCENERY | CATEGORY_BOMB| CATEGORY_MONSTER| CATEGORY_BULLET_BOSS|CATEGORY_BOSS;
static const short MASK_BOSS = CATEGORY_BOMB | CATEGORY_PLAYER | CATEGORY_BULLET ;
static const short MASK_BULLET_BOSS =  CATEGORY_PLAYER | CATEGORY_BULLET|CATEGORY_BOMB;
static const short MASK_ITEM = CATEGORY_ITEM | CATEGORY_PLAYER|CATEGORY_GROUND;
#endif // !Collision
