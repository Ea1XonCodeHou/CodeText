# 使用基础的 Ubuntu 20.04 镜像
FROM ubuntu:20.04

# 设置 DEBIAN_FRONTEND 环境变量
ENV DEBIAN_FRONTEND=noninteractive

# 设置时区环境变量并配置 tzdata
ENV TZ=Asia/Shanghai

RUN ln -fs /usr/share/zoneinfo/$TZ /etc/localtime && \
    echo $TZ > /etc/timezone && \
    apt-get update && \
    apt-get install -y tzdata

# 设置工作目录
WORKDIR /app

# 更新安装包列表并安装必要的依赖
RUN apt-get update \
    && apt-get install -y  build-essential \  			 
    && apt-get install -y  qt5-default \
    && apt-get install -y  libqt5sql5-mysql 
			      

# 复制你的项目文件到工作目录
COPY . /app

# 使用 qmake 生成 Makefile 并编译项目
RUN qmake login/login01.pro \
    && make \
    
# 删除不需要的软件
    && apt-get remove -y qt5-default \
    && apt-get remove -y build-essential \
    && apt-get autoremove -y \
    && rm -rf /var/lib/apt/lists/* \
    && rm -rm /login
    
#CMD ["./login01"]
CMD ["tail", "-f", "/dev/null"]
