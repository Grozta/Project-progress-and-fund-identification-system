
CREATE DATABASE PPF_system ;
use PPF_system;
CREATE TABLE Captain_And_Product(
    name VARCHAR(256),
    id INT ,
    sub_Project VARCHAR(256),
    project_Number INT,
    completion_Rate INT,
    apply_Fund decimal(15,2),
    review_Status varchar(256)
);
CREATE TABLE Product_And_Project(
    name VARCHAR(256),
    id INT,
    sub_Project VARCHAR(256),
    project_Number INT,
    completion_Rate TINYINT,
    curApply_Fund decimal(15,2),
    reviewer varchar(256),
    review_Status varchar(256)
);
CREATE TABLE Employee(
    id int not null primary key auto_increment,
    name VARCHAR(256),
    pwd VARCHAR(256),
    tel INT,
    pos VARCHAR(256),
    sub_Project VARCHAR(256),
    mag_Project VARCHAR(256),
    pay_Method VARCHAR(256),
    superior VARCHAR(256)
);
CREATE TABLE Project_status(
    project_Number INT,
    project_Name VARCHAR(256),
    product_Manger VARCHAR(256),
    total_Project decimal(15,2),
    used_Fund decimal(15,2),
    completion_Rate TINYINT,
    captain VARCHAR(1024)
    -- foreign key (product_Manger) references Employee (name)
);
CREATE TABLE Project_Details(
    project_Number INT,
    project_Name VARCHAR(256),
    applyer_Id INT,
    applyer_Name VARCHAR(256),
    applyer_Pos VARCHAR(256),
    header_Number INT,
    header VARCHAR(256),
    cur_Amount_Work TINYINT,
    cur_Apply_Fund decimal(15,2),
    completion_Rate TINYINT
    -- 5.5的版本的mysql不能使用外键 还有if语句
    -- foreign key (project_Number) references Project_status (project_Number),
    -- foreign key (project_Name) references Project_status (project_Name),
    -- foreign key (applyer_Id) references Employee (id),
    -- foreign key (applyer_Name) references Employee (name),
    -- foreign key (applyer_Pos) references Employee (pos),
    -- foreign key (header_Number) references Employee (id),
    -- foreign key (header) references Employee (name),
);
-- Insert rows into table 'TableName'
INSERT INTO Employee
VALUES
( null,"王城","weffdg35","1992357348","总经理",null,null,"年薪","毛科"),
( null,"卢村","234fdg35","1312357348","生产经理",null,"名山","月薪","李玉"),
( null,"科奇","tyytdg35","131235238","队长",null,"名山","月薪","卢村"),
( null,"董太奇","t12y2g35","1235238","普通员工",null,null,"时薪","科奇");

INSERT INTO Project_status
VALUES
(20150507,"山水家园","卢村",26632358.93,0,0,"李玉山 万科 董碧林"),
(20190807,"盛世展厅","图论",25623465.71,37262424,54,"李玉山 万科 董碧林");
INSERT INTO Employee
VALUES
( null,"1","1","1392357348","总经理",null,null,"年薪","毛科");
INSERT INTO Employee
VALUES
( null,"2","2","153357348","生产经理",null,null,"月薪","毛科");