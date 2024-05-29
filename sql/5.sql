
-- 视图创建

CREATE VIEW limit_5_0 AS -- 限定5星角色
SELECT *
FROM cardpool
WHERE Cycle = 0 OR (Ob_star = 5 AND Cycle = 2 AND Ob_type = 0);

CREATE VIEW limit_4_0 AS -- 限定4星角色 
SELECT *
FROM cardpool
WHERE Ob_star = 4 AND Cycle = 2;

CREATE VIEW limit_5_1 AS -- 限定5星武器
SELECT *
FROM cardpool
WHERE (Ob_star = 5 AND Cycle = 1) or (Ob_star = 5 AND Cycle = 2 AND Ob_type = 1);

CREATE VIEW limit_4_1 AS-- 限定4星武器 
SELECT *
FROM cardpool
WHERE (Ob_star = 4 AND Cycle = 1) or (Ob_star = 4 AND Cycle = 2);

CREATE VIEW normal_5 AS -- 常规5星
SELECT *
FROM cardpool
WHERE Ob_star = 5 AND Cycle = 2;

CREATE VIEW normal_4 AS -- 常规4星
SELECT *
FROM cardpool
WHERE Ob_star = 4 AND Cycle = 2;

CREATE VIEW other_3 AS -- 3星物品
SELECT *
FROM cardpool
WHERE Ob_star = 3;