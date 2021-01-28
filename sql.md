```mysql
#版本 v1.0.1
CREATE TABLE `employee`
(
    `employee_id`      	int  NOT NULL COMMENT '员工工号',
    `employee_name`     varchar(64) NOT NULL COMMENT '员工姓名',
    `phone`   			varchar(11) COMMENT '员工手机',
    `degree`   			tinyint COMMENT '员工学位',
    `status`   			tinyint COMMENT '员工状态',
    `department`     	int COMMENT '员工部门',
    `email`     		varchar(128) COMMENT '员工邮箱',
    `is_fulltime`  		tinyint COMMENT '是否转正',
    `hiredate`  		date COMMENT '入职日期',
    PRIMARY KEY (`employee_id`)
) default charset = utf8;

CREATE TABLE `attendance`
(
    `attendance_id`		int NOT NULL,
    `employee_id`    	int NOT NULL COMMENT '员工工号',
    `left_early`     	int NOT NULL DEFAULT 0 COMMENT '早退次数',
    `late`     			int NOT NULL DEFAULT 0 COMMENT '迟到次数',
    `non_punch` 		int NOT NULL DEFAULT 0 COMMENT '未打卡次数',
    `overtime`     		int NOT NULL DEFAULT 0 COMMENT '加班次数',
    `leave` 			int NOT NULL DEFAULT 0 COMMENT '请假次数',
    `calculated_day` 	int NOT NULL DEFAULT 0 COMMENT '应出勤天数',
    `att_date`  		date NOT NULL COMMENT '统计日期',
    PRIMARY KEY (`attendance_id`)
) default charset = utf8;

CREATE TABLE `salary`
(
    `salary_id`			int NOT NULL,
    `employee_id`    	int NOT NULL COMMENT '员工工号',
    `base_salary`     	int NOT NULL DEFAULT 2000 COMMENT '基本工资',
    `post_salary`     	int NOT NULL DEFAULT 0 COMMENT '岗位工资',
    `merit_salary`     	int NOT NULL DEFAULT 0 COMMENT '绩效工资',
    `social_security` 	int NOT NULL DEFAULT 0 COMMENT '社保扣款',
    `full_att_bonus` 	int NOT NULL DEFAULT 0 COMMENT '全勤奖',
    `absent_deduction` 	int NOT NULL DEFAULT 0 COMMENT '旷工扣款/次',
    `late_deduction` 	int NOT NULL DEFAULT 0 COMMENT '迟到扣款/次',
    `early_deduction` 	int NOT NULL DEFAULT 0 COMMENT '早退扣款/次',
    `overtime_bonus`    int NOT NULL DEFAULT 0 COMMENT '加班费/天',
    `before_tax`     	int DEFAULT 0 COMMENT '应发工资',#衍生属性(可删)
    `after_tax`     	int DEFAULT 0 COMMENT '实发工资',#衍生属性(可删)
    `salary_date`  		date NOT NULL COMMENT '工资日期',
    PRIMARY KEY (`salary_id`)
) default charset = utf8;

CREATE TABLE `user`
(
    `user_id`			varchar(32) NOT NULL,
    `user_pwd`			varchar(32) NOT NULL,
    `user_name`			varchar(32),
    PRIMARY KEY (`user_id`)
)default charset = utf8;
```

