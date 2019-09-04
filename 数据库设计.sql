
CREATE DATABASE PPF_system ;
use PPF_system;
CREATE TABLE Captain_And_Product(
    serial_num int not null primary key auto_increment,
    name VARCHAR(256),
    id INT,
    pos VARCHAR(256),
    sub_Project VARCHAR(256),
    project_Number INT,
    completion_Rate TINYINT,
    curApply_Fund decimal(15,2),
    review_Status varchar(256)
);
CREATE TABLE Product_And_Project(
    serial_num int not null primary key auto_increment,
    name VARCHAR(256),
    id INT,
    pos VARCHAR(256),
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
    captain VARCHAR(1024),
    completion_Rate TINYINT,
    used_Fund decimal(15,2),
    total_Project decimal(15,2)
    -- foreign key (product_Manger) references Employee (name)
);
CREATE TABLE Project_Details(
    applyer_Name VARCHAR(256),
    applyer_Id INT,
    applyer_Pos VARCHAR(256),
    project_Number INT,
    project_Name VARCHAR(256),
    header VARCHAR(256),
    cur_Amount_Work TINYINT,
    completion_Rate TINYINT,
    cur_Apply_Fund decimal(15,2)

    -- 5.5的版本的mysql不能使用外键 还有if语句
    -- foreign key (project_Number) references Project_status (project_Number),
    -- foreign key (project_Name) references Project_status (project_Name),
    -- foreign key (applyer_Id) references Employee (id),
    -- foreign key (applyer_Name) references Employee (name),
    -- foreign key (applyer_Pos) references Employee (pos),
    -- foreign key (header_Number) references Employee (id),
    -- foreign key (header) references Employee (name),
    -- Insert rows into table 'TableName'
);
INSERT INTO Employee (
    id ,name ,  pwd, tel ,pos , sub_Project , mag_Project ,pay_Method,superior)
VALUES
    ( null,"王城","weffdg35","1992357348","总经理",null,null,"年薪","毛科"),
    ( null,"卢村","234fdg35","1312357348","生产经理",null,"名山","月薪","李玉"),
    ( null,"科奇","tyytdg35","131235238","队长",null,"名山","月薪","卢村"),
    ( null,"董太奇","t12y2g35","1235238","普通员工",null,null,"时薪","科奇");

INSERT INTO Project_status(
    project_Number ,project_Name ,product_Manger ,captain ,completion_Rate ,used_Fund ,total_Project  )
VALUES
    (20150507,"山水家园","卢村","徐勇 罗凯，周董",57, 5686596,9595963),
    (20170707,"碧水云天","李琦","徐勇 赵崩山，黄科",89, 8992596,9595963),
    (20160107,"天下传说","左轮","无双，秋千，大猪",0, 0,95212),
    (20190807,"盛世展厅","图论","赵三",51,312546,685475);


INSERT INTO Employee(
    id , name , pwd , tel , pos , sub_Project , mag_Project , pay_Method , superior
)
VALUES
    ( null,"1","1","1392357348","总经理",null,null,"年薪","毛科"),
    ( null,"2","2","1533573438","生产经理",null,null,"月薪","姚娜"),
    ( null,"3","3","1375734283","队长",null,null,"月薪","董碧虎");
   
INSERT INTO Product_And_Project(name,id,pos,sub_Project,project_Number,completion_Rate,curApply_Fund,reviewer,review_Status)
VALUES
    ("杜康",5682,"队长","山水家园",20170903,1.25,56248,"姚云","未处理"),
    ("李玉",5514,"队长","山水家园",20170903,0.89,15786,"姚云","未处理"),
    ("周归仁",685,"队长","碧水云天",20091101,16.89,18545786,"姚云","未处理");

insert into Project_Details( applyer_Name ,applyer_Id ,applyer_Pos ,project_Number ,project_Name ,header ,cur_Amount_Work ,completion_Rate ,cur_Apply_Fund
) 
VALUES
    ("王五",8546,"队长",20140502,"山水家园","刘志",5,11,4342245),
    ("王强",8546,"队长",20110809,"碧水云天","姚云",1,43,562345),
    ("李云天",8546,"队长",20091109,"山水家园","刘志",18,89,123245),
    ("夏天",8546,"队长",20200901,"盛世展厅","姚云",1,23,76534),
    ("刘鑫",8546,"队长",20140718,"山水家园","刘志",1,99,23245),
    ("店小二",8546,"队长",20111026,"天下传说","姚云",43,90,54245),
    ("李云龙",8546,"队长",20091108,"山水家园","刘志",1,57,765245);
drop table Project_status;
drop TABLE Captain_And_Product;
drop TABLE Product_And_Project;

update Product_And_Project set review_Status = '同意' where serial_num = 2;