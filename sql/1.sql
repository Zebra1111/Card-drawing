
-- 建表

-- 用户表创建
create table User( 
	UID char(9) primary key,
	Password Varchar(16) not null,
	User_name Varchar(12) not null,
	Cum_num1_0 Int Default 0,-- 出金则清零
	Cum_num2_0 Int Default 0,-- 出紫则清零
	Cum_num1_1 Int Default 0,
	Cum_num2_1 Int Default 0,
	Cum_num1_2 Int Default 0,
	Cum_num2_2 Int Default 0,
	Treasure int Default 4000
);

-- 仓库表创建
create table Warehouse( 
	Ob_name Varchar(50) not null,
	UID	Char(9) not null,
	Ob_num Int Default 0,
	Ob_type INT Check(Ob_type in(0,1)),
	Ob_star INT,
	primary key (Ob_name,UID)
);

-- 卡池表创建
create table Cardpool(
	Ob_no INT Primary key,
	Ob_name	Varchar(50) NOT null,
	Ob_star Int Not null,
	Cycle	Int	Check(Cycle in(0,1,2)),
	Ob_type Int Check(Ob_type in(0,1))
);

-- 历史记录表创建
create table History(
	Order_num INT PRIMARY KEY auto_increment,
	Time datetime	Not null,
	UID	Char(9) Not null,
	Ob_no INT Not null,
	Ob_name	Varchar(50) Not null,
	Ob_star INT NOT null,
	Ob_type Int Check(Ob_type in(0,1)),
	Cycle	Int	Check(Cycle in(0,1,2))
);
