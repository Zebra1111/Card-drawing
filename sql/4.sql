
--  触发器实现
 
-- 抽取物品存入用户仓库
CREATE TRIGGER Sto_house
AFTER INSERT ON history
FOR EACH ROW
BEGIN
	SET @num_ = 0;
	SELECT Ob_num INTO @num_ FROM warehouse WHERE UID = new.UID and Ob_name = new.Ob_name;
	
	IF @num_ = 0 THEN
		-- 等于0说明用户还没有该物品，故向仓库中插入数据，数量加一
		INSERT INTO warehouse(Ob_name,UID,Ob_type,Ob_star) VALUES(new.Ob_name, new.UID, new.Ob_type, (SELECT Ob_star FROM cardpool WHERE Ob_name = new.Ob_name));
		UPDATE warehouse SET Ob_num = @num_ + 1 WHERE UID = new.UID and Ob_name = new.Ob_name;
	ELSE
		-- 不等于0说明用户已拥有该物品，只需把物品数量加一
		UPDATE warehouse SET Ob_num = @num_ + 1 WHERE UID = new.UID and Ob_name = new.Ob_name;
	END IF;
END;


-- 物品达到上限后将会返还原石（命座）
CREATE TRIGGER Life_num
BEFORE UPDATE ON warehouse
FOR EACH ROW
BEGIN
    IF NEW.ob_num > 7  AND new.ob_type=0 AND new.ob_star=5 THEN
       UPDATE `user` SET Treasure =  Treasure + (NEW.ob_num - 7)*800 WHERE old.UID=UID;
       set new.ob_num = 7 ;
    END IF;
		IF NEW.ob_num > 7  AND new.ob_type=0 AND new.ob_star=4 THEN
       UPDATE `user` SET Treasure =  Treasure + (NEW.ob_num - 7)*160 WHERE old.UID=UID;
       set new.ob_num = 7 ;
    END IF;
END;



-- 注销用户后在history和warehouse表中删除对应信息
CREATE TRIGGER DELETE_user
BEFORE DELETE ON `user`
FOR EACH ROW
BEGIN
	DELETE FROM history WHERE UID  = old.UID;
	DELETE FROM warehouse WHERE UID =  old.UID;
END;






















