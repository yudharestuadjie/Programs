CREATE DATABASE PesananKue;
USE PesananKue;

CREATE TABLE Toko(
Id_pesanan char (10)not null,
Id_pelanggan char (10) not null,
Jenis_pembayaran varchar (8) not null,
Tanggal date,
CONSTRAINT Toko_pk PRIMARY KEY (Id_pesanan)
) engine=InnoDB;

show tables;

CREATE TABLE Pelanggan(
Id_pelanggan char (10) not null,
Nama_pelanggan varchar (20) not null,
Alamat_pelanggan varchar (30) not null,
Telp_pelanggan decimal,
CONSTRAINT Pelanggan_pk PRIMARY KEY (Id_customer)
) engine=InnoDB;

show tables;

CREATE TABLE Makanan(
Id_makanan char (10) not null,
Nama_makanan char (10) not null,
Harga decimal, 
Jumlah int (3),
CONSTRAINT Makanan_pk PRIMARY KEY (Id_makanan) 
) engine=InnoDB;

show tables;

CREATE TABLE DetailPesanan(
Id_pesanan char (10)not null,
Id_makanan char (10) not null,
Jumlah int (3),
Harga decimal
) engine=InnoDB;

show tables;

CREATE TABLE Kasir(
Id_kasir char (10) not null,
Id_pesanan char (10) not null,
Nama_kasir varchar (20) not null,
CONSTRAINT Kasir_pk PRIMARY KEY (Id_kasir)
) engine=InnoDB;

show tables;

ALTER TABLE Pelanggan ADD Gender varchar (10) CONSTRAINT Pelanggan_pk check(Gender =  'Male' or Gender = 'Female');
select * from Pelanggan; 
 
DROP TABLE DetailPesanan;

insert into Toko (Id_pesanan, Id_pelanggan, Tanggal, Jenis_pembayaran) values ('HF101','PF001','2021-12-7','Tunai');
insert into Toko (Id_pesanan, Id_pelanggan, Tanggal, Jenis_pembayaran) values ('HF102','PF002','2021-12-8','Tunai');
insert into Toko (Id_pesanan, Id_pelanggan, Tanggal, Jenis_pembayaran) values ('HF103','PF003','2021-12-9','Tunai');
insert into Toko (Id_pesanan, Id_pelanggan, Tanggal, Jenis_pembayaran) values ('HF104','PF004','2021-12-11','E-Money');
insert into Toko (Id_pesanan, Id_pelanggan, Tanggal, Jenis_pembayaran) values ('HF105','PF005','2021-12-12','E-Money');
insert into Toko (Id_pesanan, Id_pelanggan, Tanggal, Jenis_pembayaran) values ('HF106','PF006','2021-12-13','E-Money');
insert into Toko (Id_pesanan, Id_pelanggan, Tanggal, Jenis_pembayaran) values ('HF107','PF007','2021-12-15','Tunai');
insert into Toko (Id_pesanan, Id_pelanggan, Tanggal, Jenis_pembayaran) values ('HF108','PF008','2021-12-17','Tunai');

insert into Pelanggan(Id_pelanggan, Nama_pelanggan, Telp_pelanggan, Alamat_pelanggan, Gender) values('PF001','Dina','0821224567','Jl. Kenanga No. 101','FEMALE');
insert into Pelanggan(Id_pelanggan, Nama_pelanggan, Telp_pelanggan, Alamat_pelanggan, Gender) values('PF002','Angga','0821335476','Jl. Mawar No. 001','MALE');
insert into Pelanggan(Id_pelanggan, Nama_pelanggan, Telp_pelanggan, Alamat_pelanggan, Gender) values('PF003','lita','0821224500','Jl. Melati No. 117','FEMALE');
insert into Pelanggan(Id_pelanggan, Nama_pelanggan, Telp_pelanggan,  Alamat_pelanggan, Gender) values('PF004','Joko','0821784501','Jl. Anggrek No. 181','MALE');
insert into Pelanggan(Id_pelanggan, Nama_pelanggan, Telp_pelanggan,  Alamat_pelanggan, Gender) values('PF005','Toni','0822004569','Jl. Kamboja No. 008','MALE');
insert into Pelanggan(Id_pelanggan, Nama_pelanggan, Telp_pelanggan,  Alamat_pelanggan, Gender) values('PF006','Lala','0821224000','Jl. Poros Tengah No. 115','FEMALE');
insert into Pelanggan(Id_pelanggan, Nama_pelanggan, Telp_pelanggan,  Alamat_pelanggan, Gender) values('PF007','Budi','0897224567','Jl. Curug No. 102','MALE');
insert into Pelanggan(Id_pelanggan, Nama_pelanggan, Telp_pelanggan,  Alamat_pelanggan, Gender) values('PF008','Bery','0827224111','Jl. Tulip No. 108','MALE');

insert into Makanan(Id_makanan, Nama_makanan, Harga, Jumlah) values ('FCD281','Choco Lava Cake', 'Rp 35000', '2');
insert into Makanan(Id_makanan, Nama_makanan, Harga, Jumlah) values ('FCD284','Rainbow Cake', 'Rp 30000', '1');
insert into Makanan(Id_makanan, Nama_makanan, Harga, Jumlah) values ('FCD286','Snow Cake', 'Rp 32000', '3');
insert into Makanan(Id_makanan, Nama_makanan, Harga, Jumlah) values ('FCD286','Snow Cake', 'Rp 32.000', '1');
insert into Makanan(Id_makanan, Nama_makanan, Harga, Jumlah) values ('FCD286','Snow Cake', 'Rp 32000', '2');
insert into Makanan(Id_makanan, Nama_makanan, Harga, Jumlah) values ('FCD281','Choco Lava Cake', 'Rp 35000', '2');
insert into Makanan(Id_makanan, Nama_makanan, Harga, Jumlah) values ('FCD281','Choco Lava Cake', 'Rp 35000', '1');
insert into Makanan(Id_makanan, Nama_makanan, Harga, Jumlah) values ('FCD284','Rainbow Cake', 'Rp 30000', '1');

insert into kasir(Id_kasir, Nama_kasir, Id_pesanan) values ('KF011','Herman','HF101');
insert into kasir(Id_kasir, Nama_kasir, Id_pesanan) values('KF011','Herman','HF102');
insert into kasir(Id_kasir, Nama_kasir, Id_pesanan) values('KF011','Herman','HF103');
insert into kasir(Id_kasir, Nama_kasir, Id_pesanan) values('KF011','Herman','HF104');
insert into kasir(Id_kasir, Nama_kasir, Id_pesanan) values('KF011','Herman','HF105');
insert into kasir(Id_kasir, Nama_kasir, Id_pesanan) values('KF011','Herman','HF106');
insert into kasir(Id_kasir, Nama_kasir, Id_pesanan) values('KF011','Herman','HF107');
insert into kasir(Id_kasir, Nama_kasir, Id_pesanan) values('KF011','Herman','HF108');

select *from Toko;
select *from Pelanggan;
select * from Makanan;
select * from Kasir;

drop database PesananKue;