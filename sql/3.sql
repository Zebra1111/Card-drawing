
-- 功能实现

-- 用户登录
CREATE PROCEDURE User_login(in Id char(9),in Pwd varchar(16),out result1 int)
BEGIN
	
	DECLARE get_ int DEFAULT -1;
	
	SELECT * 
	FROM `user`
	WHERE UID = Id and `Password` = Pwd;
	
	SELECT Treasure
	INTO get_
	FROM `user`
	WHERE UID = Id and `Password` = Pwd;
	
	IF get_ > -1 THEN
		SET result1 = 1;
	ELSE
		SET result1 = 0;
	END IF;

END;
call User_login('123','123',@result1);
DROP PROCEDURE User_login;
SELECT @result1;

-- 注册函数
CREATE PROCEDURE register(in UID_ char(9), in Password_ varchar(16), in name_ varchar(12), out result3 int)
BEGIN 

	DECLARE sum_ INT ;-- 查重
	SELECT COUNT(*) INTO sum_ FROM `user` WHERE UID = UID_;
	
	IF sum_ > 0 THEN 
		SET result3 = 0;
	ELSE 
		SET result3 = 1;
	END IF;
	
	IF UID_ IS NULL OR UID_ = '' THEN
		SET result3 = 0;
	END IF;
	
	IF result3 = 1 THEN
		INSERT INTO `user` VALUES(UID_,Password_,name_,0,0,4000);
	END IF;
	
END;

-- 抽奖功能(具有保底机制)
CREATE PROCEDURE Draw(in id char(9),in cycle_ int, out result2 int)
BEGIN
	
	DECLARE treasure_ INT DEFAULT 0;-- 用户原石
	DECLARE star_ INT;-- 物品星级
	DECLARE no_ INT;-- 物品编号
	DECLARE name_ Varchar(50);-- 物品名称
	DECLARE type_ INT;-- 物品类型
	DECLARE gold INT DEFAULT 0;-- 金
	DECLARE purple INT DEFAULT 0;-- 紫
	
	SELECT Treasure INTO treasure_
	FROM `user`
	WHERE UID = id;
	
	IF treasure_ - 160 < 0 THEN-- 判断本次抽取是否合法
		SET result2 = 0;
	ELSE
		UPDATE `user` SET Treasure = Treasure - 160 WHERE UID = id;-- 更新原石
		SET result2 = 1;
		CASE 
			WHEN cycle_ = 0 THEN
			
					SELECT Cum_num1_0 + 1 INTO gold-- 用来判断本次抽取是否触发保底
					FROM `user`
					WHERE UID = id;
					
					SELECT Cum_num2_0 + 1 INTO purple-- 用来判断本次抽取是否触发保底
					FROM `user`
					WHERE UID = id;
					
					UPDATE `user` SET Cum_num1_0 = Cum_num1_0 + 1 WHERE UID = id;
					UPDATE `user` SET Cum_num2_0 = Cum_num2_0 + 1 WHERE UID = id;
					
				IF gold = 90 THEN-- 判断本次抽取是否触发保底
					SELECT Ob_name, Ob_no, Ob_star, Ob_type INTO name_, no_, star_, type_ FROM limit_5_0 ORDER BY RAND() LIMIT 1;
					INSERT INTO history VALUES(null, NOW(), id, no_, name_, star_, type_, cycle_);
					UPDATE `user` SET Cum_num1_0 = 0 WHERE UID = id;
				ELSEIF purple = 10 or purple = 11 THEN	-- 判断本次抽取是否触发保底
					SELECT Ob_name, Ob_no, Ob_star, Ob_type INTO name_, no_, star_, type_ FROM limit_4_0 ORDER BY RAND() LIMIT 1;
					INSERT INTO history VALUES(null, NOW(), id, no_, name_, star_, type_, cycle_);
					UPDATE `user` SET Cum_num2_0 = 0 WHERE UID = id;
				ELSE
					SELECT CEILING(RAND()*10) INTO star_;
					IF star_ >= 0 AND star_ <= 5 THEN
						SET star_ = 3;
						SELECT Ob_name,Ob_no,Ob_type INTO name_, no_, type_ FROM other_3 ORDER BY RAND() LIMIT 1;
						INSERT INTO history VALUES(null, NOW(), id, no_, name_, star_, type_, cycle_);
					ELSEIF star_ >= 6 AND star_ <= 9 THEN
						SET star_ = 4;
						SELECT Ob_name,Ob_no,Ob_type INTO name_, no_, type_ FROM limit_4_0 ORDER BY RAND() LIMIT 1;
						INSERT INTO history VALUES(null, NOW(), id, no_, name_, star_, type_, cycle_);
						UPDATE `user` SET Cum_num2_0 = 0 WHERE UID = id;
					ELSEIF star_ = 10 THEN
						SET star_ = 5;
						SELECT Ob_name,Ob_no,Ob_type INTO name_, no_, type_ FROM limit_5_0 ORDER BY RAND() LIMIT 1;
						INSERT INTO history VALUES(null, NOW(), id, no_, name_, star_, type_, cycle_);
						UPDATE `user` SET Cum_num1_0 = 0 WHERE UID = id;
					END IF;					
				END IF;
				
				
			WHEN cycle_ = 1 THEN
			
					SELECT Cum_num1_1 + 1 INTO gold-- 用来判断本次抽取是否触发保底
					FROM `user`
					WHERE UID = id;
	
					SELECT Cum_num2_1 + 1 INTO purple-- 用来判断本次抽取是否触发保底
					FROM `user`
					WHERE UID = id;
					
					UPDATE `user` SET Cum_num1_1 = Cum_num1_1 + 1 WHERE UID = id;
					UPDATE `user` SET Cum_num2_1 = Cum_num2_1 + 1 WHERE UID = id;
					
				IF gold = 90 THEN-- 判断本次抽取是否触发保底
					SELECT Ob_name, Ob_no, Ob_star, Ob_type INTO name_, no_, star_, type_ FROM limit_5_1 ORDER BY RAND() LIMIT 1;
					INSERT INTO history VALUES(null, NOW(), id, no_, name_, star_, type_, cycle_);
					UPDATE `user` SET Cum_num1_1 = 0 WHERE UID = id;
				ELSEIF purple = 10 or purple = 11 THEN	-- 判断本次抽取是否触发保底
					SELECT Ob_name, Ob_no, Ob_star, Ob_type INTO name_, no_, star_, type_ FROM limit_4_1 ORDER BY RAND() LIMIT 1;
					INSERT INTO history VALUES(null, NOW(), id, no_, name_, star_, type_, cycle_);
					UPDATE `user` SET Cum_num2_1 = 0 WHERE UID = id;
				ELSE
					SELECT CEILING(RAND()*10) INTO star_;
					IF star_ >= 0 AND star_ <= 5 THEN
						SET star_ = 3;
						SELECT Ob_name,Ob_no,Ob_type INTO name_, no_, type_ FROM other_3 ORDER BY RAND() LIMIT 1;
						INSERT INTO history VALUES(null, NOW(), id, no_, name_, star_, type_, cycle_);
					ELSEIF star_ >= 6 AND star_ <= 9 THEN
						SET star_ = 4;
						SELECT Ob_name,Ob_no,Ob_type INTO name_, no_, type_ FROM limit_4_1 ORDER BY RAND() LIMIT 1;
						INSERT INTO history VALUES(null, NOW(), id, no_, name_, star_, type_, cycle_);
						UPDATE `user` SET Cum_num2_1 = 0 WHERE UID = id;
					ELSEIF star_ = 10 THEN
						SET star_ = 5;
						SELECT Ob_name,Ob_no,Ob_type INTO name_, no_, type_ FROM limit_5_1 ORDER BY RAND() LIMIT 1;
						INSERT INTO history VALUES(null, NOW(), id, no_, name_, star_, type_, cycle_);
						UPDATE `user` SET Cum_num1_1 = 0 WHERE UID = id;
					END IF;					
				END IF;
				
				
			WHEN cycle_ = 2 THEN
			
					SELECT Cum_num1_2 + 1 INTO gold-- 用来判断本次抽取是否触发保底
					FROM `user`
					WHERE UID = id;
	
					SELECT Cum_num2_2 + 1 INTO purple-- 用来判断本次抽取是否触发保底
					FROM `user`
					WHERE UID = id;
					
					UPDATE `user` SET Cum_num1_2 = Cum_num1_2 + 1 WHERE UID = id;
					UPDATE `user` SET Cum_num2_2 = Cum_num2_2 + 1 WHERE UID = id;
					
				IF gold = 90 THEN-- 判断本次抽取是否触发保底
					SELECT Ob_name, Ob_no, Ob_star, Ob_type INTO name_, no_, star_, type_ FROM normal_5 ORDER BY RAND() LIMIT 1;
					INSERT INTO history VALUES(null, NOW(), id, no_, name_, star_, type_, cycle_);
					UPDATE `user` SET Cum_num1_2 = 0 WHERE UID = id;
				ELSEIF purple = 10 or purple = 11 THEN	-- 判断本次抽取是否触发保底
					SELECT Ob_name, Ob_no, Ob_star, Ob_type INTO name_, no_, star_, type_ FROM normal_4 ORDER BY RAND() LIMIT 1;
					INSERT INTO history VALUES(null, NOW(), id, no_, name_, star_, type_, cycle_);
					UPDATE `user` SET Cum_num2_2 = 0 WHERE UID = id;
				ELSE
					SELECT CEILING(RAND()*10) INTO star_;
					IF star_ >= 0 AND star_ <= 5 THEN
						SET star_ = 3;
						SELECT Ob_name,Ob_no,Ob_type INTO name_, no_, type_ FROM other_3 ORDER BY RAND() LIMIT 1;
						INSERT INTO history VALUES(null, NOW(), id, no_, name_, star_, type_, cycle_);
					ELSEIF star_ >= 6 AND star_ <= 9 THEN
						SET star_ = 4;
						SELECT Ob_name,Ob_no,Ob_type INTO name_, no_, type_ FROM normal_4 ORDER BY RAND() LIMIT 1;
						INSERT INTO history VALUES(null, NOW(), id, no_, name_, star_, type_, cycle_);
						UPDATE `user` SET Cum_num2_2 = 0 WHERE UID = id;
					ELSEIF star_ = 10 THEN
						SET star_ = 5;
						SELECT Ob_name,Ob_no,Ob_type INTO name_, no_, type_ FROM normal_5 ORDER BY RAND() LIMIT 1;
						INSERT INTO history VALUES(null, NOW(), id, no_, name_, star_, type_, cycle_);
						UPDATE `user` SET Cum_num1_2 = 0 WHERE UID = id;
					END IF;					
				END IF;
		END CASE;	
	END IF;
	END;
CALL Draw('123',2,@result2);
SELECT @result2;



-- 插入新角色武器
CREATE PROCEDURE new_ob(in num_ int ,in ob_name_ VARCHAR(50), in star_ INT, in Cycle_ INT,in Type_ int, out result4 int)
BEGIN 
	IF ob_name_ IS NULL OR ob_name_ = '' THEN
		SET result4 = 0;
	ELSE 
		SET result4 = 1;
	END IF;
	
	IF result4 = 1 THEN
		INSERT INTO cardpool VALUES(num_,ob_name_ ,star_,Cycle_,Type_);
	END IF;
END;


-- 充值
CREATE PROCEDURE Recharge(in id char(9), in num int, out result5 int)
BEGIN
	IF num < 0 or num IS NUll THEN
		SET result5 = 0;
	ELSE
		SET result5 = 1;
		UPDATE `user` SET Treasure = Treasure + num * 10 WHERE UID = id;
	END IF;
END;


-- 修改用户密码昵称
CREATE PROCEDURE update_user(in UID_ char(9),in password_ VARCHAR(16), in User_name_ varchar(12), out result6 int)
BEGIN 
	IF password_ IS NULL OR password_ = '' or User_name_ IS NULL OR User_name_ = '' THEN
		SET result6 = 0;
	ELSE 
		SET result6 = 1;
	END IF;
	
	IF result6 = 1 THEN
		UPDATE user SET `Password` = password_ where UID = UID_;
		UPDATE user SET User_name = User_name_ where UID = UID_;
	END IF;
END;








