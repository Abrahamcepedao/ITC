/*create database Company

SET DATEFORMAT mdy

create table "Departamento" (
    "d_numero" "int" NOT NULL,
    "d_nombre" nvarchar (30) NULL,
    "admin_rfc" nvarchar (30) NULL,
    "fecha_inicio_adm" "datetime" NULL,
    CONSTRAINT "PK_Departamento" PRIMARY key CLUSTERED (
        "d_numero"
    )
)

create table "Empleado" (
    "rfc" nvarchar (30) NOT NULL,
    "nombre" nvarchar (30) NOT NULL,
    "apellidop" nvarchar (30) NOT NULL,
    "apellidom" nvarchar (30) NOT NULL,
    "fecha_nac" "datetime" NULL,
    "direccion" nvarchar (30) NULL,
    "sexo" nvarchar (5) NULL,
    "salario" "int" NULL,
    "rfc_supervisor" nvarchar (30) NULL,
    "dno" "int" NULL,
    CONSTRAINT "PK_Empleado" PRIMARY key CLUSTERED (
        "rfc"
    )
)

create table "Locales_dept" (
    "d_numero" "int" NOT NULL,
    "d_localizacion" nvarchar (30) NOT NULL,
    CONSTRAINT "PK_Locales_dept" PRIMARY KEY CLUSTERED (
        "d_numero", "d_localizacion"
    )
)

create table "Trabaje_en" (
    "e_rfc" nvarchar (30) NOT NULL,
    "pno" "int" NOT NULL,
    "horas" "int" NULL,
    CONSTRAINT "PK_Trabaje_en" PRIMARY KEY CLUSTERED (
        "e_rfc", "pno"
    )
)

create table "Proyecto" (
    "p_numero" "int" NOT NULL,
    "p_nombre" nvarchar (30) NULL,
    "p_local" nvarchar (30) NULL,
    "d_num" "int" NULL,
    CONSTRAINT "PK_Proyecto" PRIMARY KEY CLUSTERED (
        "p_numero"
    )
)

create table "Dependiente" (
    "e_rfc" nvarchar (30) NOT NULL,
    "nombre_dependiente" nvarchar (30) NOT NULL,
    "sexo" nvarchar (30) NOT NULL,
    "fecha_nac" "datetime" NULL,
    "relacion" nvarchar (30) NULL,
    CONSTRAINT "PK_Dependiente" PRIMARY KEY CLUSTERED (
        "e_rfc", "nombre_dependiente"
    )
)

alter table Empleado
add constraint "FK_Emp_dep" FOREIGN key ("dno") REFERENCES Departamento("d_numero")

alter table Departamento
add constraint "FK_Dep_emp" FOREIGN key ("admin_rfc") REFERENCES Empleado("rfc")



alter table Locales_dept
add constraint "FK_Loc_dep" FOREIGN key ("d_numero") REFERENCES Departamento("d_numero")



alter table Proyecto
add constraint "FK_pro_dep" FOREIGN key ("d_num") REFERENCES Departamento("d_numero")

alter table Proyecto
add constraint "FK_pro_dep" FOREIGN key ("d_num") REFERENCES Departamento("d_numero")

alter table Dependiente
add constraint "FK_dep_rfc" foreign KEY ("e_rfc") REFERENCES Empleado("rfc")

*/





use Company


INSERT INTO "Empleado" VALUES ('ART7383HA', 'Abraham', 'Cepeda', 'Oseguera', '11/19/1999', 'mi direccion','h', 10000, 'GAH728292H', 1)
INSERT INTO "Empleado" VALUES ('AHH8373DD', 'Juan', 'Perez', 'Rodriguez', '12/02/1999', 'Xtakay','h', 20000, 'GAH728292H', 1)
INSERT INTO "Empleado" VALUES ('LDJ7338JS', 'Alex', 'Canto', 'Ortiz', '02/07/1998', 'Monterrey','h', 30000, 'GAH728292H', 1)
INSERT INTO "Empleado" VALUES ('GAH728292H', 'Daniela', 'Martinez', 'Cepeda', '08/15/1989', 'Merida','m', 50000, NULL, 1)
INSERT INTO "Empleado" VALUES ('SLKS16616', 'Pat', 'Perez', 'Spieth', '10/12/2000', 'Ciudad de mexico','h', 100000, 'GAH728292H', 1)
INSERT INTO "Empleado" VALUES ('JJD7383JD', 'Renata', 'Gonzalez', 'Jimenez', '10/18/1998', 'Coahuila','m', 30000, 'HDH73783J', 2)
INSERT INTO "Empleado" VALUES ('HDH73783J', 'Fernanda', 'Anaya', 'Anaya', '10/18/1996', 'Torreon','m', 84877, NULL, 2)
INSERT INTO "Empleado" VALUES ('ODH6388HH', 'Camila', 'Ugalde', 'Flores', '10/18/1992', 'Acapulco','m', 57378, 'HDH73783J', 2)
INSERT INTO "Empleado" VALUES ('LSJ8828JJ', 'Paula', 'Trejolerdo', 'Ugalde', '10/18/1993', 'Veracruz','m', 37373, 'HDH73783J', 2)
INSERT INTO "Empleado" VALUES ('DHK83838H', 'Jimena', 'Cepeda', 'Oseguera', '10/18/1993', 'Veracruz','m', 37373, 'DHH73839H', 3)
INSERT INTO "Empleado" VALUES ('DHH73839H', 'Ricardo', 'Torres', 'Valdez', '10/18/1993', 'Veracruz','h', 37373, NULL, 3)


INSERT INTO "Empleado" VALUES ('JSK73838J', 'Rafael', 'Thomassiny', 'Hernaiz', '09/27/1999', 'Veracruz','h', 37839, 'ZBN38389N', 5)
INSERT INTO "Empleado" VALUES ('PAL10847F', 'Gabriel', 'Gutierrez', 'Castillo', '10/03/1999', 'Veracruz','h', 27848, 'ZBN38389N', 5)
INSERT INTO "Empleado" VALUES ('ZXZ278338', 'Emilio', 'Fernandez', 'Ceballos', '04/30/2000', 'Veracruz','h', 28739, 'ZBN38389N', 5)
INSERT INTO "Empleado" VALUES ('ZBN38389N', 'Lorena', 'Reyna', 'Gutierrez', '10/18/1993', 'Veracruz','h', 98822, NULL, 5)


INSERT INTO "Departamento" VALUES (1, 'Investigación y desarrollo', 'GAH728292H', '10/20/2007')
INSERT INTO "Departamento" VALUES (2, 'Desarrollo Web', 'HDH73783J', '03/13/2008')
INSERT INTO "Departamento" VALUES (3, 'Finanzas', 'DHH73839H', '07/12/2009')
INSERT INTO "Departamento" VALUES (5, 'Mercadotecnia', 'DHH73839H', '07/12/2006')


INSERT INTO "Locales_dept" values (1, 'Merida')
INSERT INTO "Locales_dept" values (2, 'Monterrey')
INSERT INTO "Locales_dept" values (3, 'Acapulco')


INSERT INTO "Trabaje_en" VALUES ('ART7383HA', 1, 1233)
INSERT INTO "Trabaje_en" VALUES ('AHH8373DD', 1, 4872)
INSERT INTO "Trabaje_en" VALUES ('LDJ7338JS', 1, 2828)
INSERT INTO "Trabaje_en" VALUES ('GAH728292H', 1, 223)
INSERT INTO "Trabaje_en" VALUES ('SLKS16616', 2, 2992)
INSERT INTO "Trabaje_en" VALUES ('JJD7383JD', 2, 1839)
INSERT INTO "Trabaje_en" VALUES ('HDH73783J', 2, 1949)
INSERT INTO "Trabaje_en" VALUES ('ODH6388HH', 2, 1983)
INSERT INTO "Trabaje_en" VALUES ('LSJ8828JJ', 2, 1388)
INSERT INTO "Trabaje_en" VALUES ('DHK83838H', 3, 1183)
INSERT INTO "Trabaje_en" VALUES ('DHH73839H', 3, 1283)
INSERT INTO "Trabaje_en" VALUES ('ODH6388HH', 5, 3738)
INSERT INTO "Trabaje_en" VALUES ('LSJ8828JJ', 5, 9227)
INSERT INTO "Trabaje_en" VALUES ('DHK83838H', 5, 7288)
INSERT INTO "Trabaje_en" VALUES ('DHH73839H', 5, 7289)


INSERT INTO "Proyecto" values (1, 'desarrollo web ternium', 1, 1)
INSERT INTO "Proyecto" values (2, 'desarrollo app ternium', 2, 2)
INSERT INTO "Proyecto" values (5, 'base de datos ternium', 1, 1)
INSERT INTO "Proyecto" values (3, 'marketing ternium', 3, 5)


INSERT INTO "Dependiente" values ('ART7383HA', 'Ignacio', 'h', '01/29/1968', 'padre')
INSERT INTO "Dependiente" values ('ART7383HA', 'Rocio', 'm', '09/09/1974', 'madre')
INSERT INTO "Dependiente" values ('ART7383HA', 'Jimena', 'm', '11/26/2001', 'hermana')
INSERT INTO "Dependiente" values ('AHH8373DD', 'Natalia', 'm', '09/09/2003', 'prima')
INSERT INTO "Dependiente" values ('LDJ7338JS', 'Daniela', 'm', '06/03/2000', 'prima')


SELECT * from Dependiente


/* 1 */

select CONCAT(e.nombre, ' ', e.apellidop, ' ', e.apellidom) as NombreCompleto, e.direccion
from Empleado e 
where e.dno=
    (select d_numero 
    from Departamento 
    where d_nombre='Investigación y desarrollo'


/* 2 */

select p.p_numero, d.d_numero, e.apellidop, e.direccion, e.fecha_nac from Empleado e, Departamento d, Proyecto p
    where e.rfc=(
        select d.admin_rfc from Departamento d 
            where d.d_numero=(
                select l.d_numero from Locales_dept l 
                    where l.d_localizacion='Monterrey'
            )
    )
    and d.d_numero=(
        select p.d_num from Proyecto p
            where p.p_local=(
                select l.d_numero from Locales_dept l
                    where l.d_localizacion='Monterrey'
            )
    ) 
    and p.d_num=(
        select d.d_numero from Departamento d
            where d.d_numero=(select l.d_numero from Locales_dept l
                where l.d_localizacion='Monterrey'
            )
    )

/* 3 */

select CONCAT(e.nombre, ' ', e.apellidop, ' ', e.apellidom) as NombreCompleto 
from Empleado e
LEFT OUTER JOIN Trabaje_en t on t.e_rfc=e.rfc
where t.pno=5


/* 4 */
select p.p_numero from Proyecto p
LEFT OUTER JOIN Trabaje_en t on t.pno=p.p_numero
LEFT OUTER JOIN Empleado e on e.rfc=t.e_rfc
where e.apellidop='Perez'




/* 5 */
select CONCAT(e.nombre, ' ', e.apellidop, ' ', e.apellidom) as NombreCompleto, e.rfc 
from Empleado e
LEFT OUTER JOIN Dependiente d on d.e_rfc=e.rfc
where e.rfc not in(select d.e_rfc from Dependiente d)

/* 6 */

select DISTINCT CONCAT(e.nombre, ' ', e.apellidop, ' ', e.apellidom) as NombreCompleto 
from Empleado e
LEFT OUTER JOIN Dependiente d on d.e_rfc=e.rfc
where e.rfc in (d.e_rfc)