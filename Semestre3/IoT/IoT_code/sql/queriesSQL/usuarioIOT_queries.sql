-- 1. count *
-- 1.1 aplicacion
SELECT COUNT(*) FROM aplicacion
-- 1.2 empleado_venta
SELECT COUNT(*) FROM empleado_venta
-- 1.3 modulo
SELECT COUNT(*) FROM modulo
-- 1.4 modulo_puesto
SELECT COUNT(*) FROM modulo_puesto
-- 1.5 puesto_empleado_venta
SELECT COUNT(*) FROM puesto_empleado_venta
-- 1.6 sub_modulo
SELECT COUNT(*) FROM sub_modulo
-- 1.7 sub_modulo_puesto
SELECT COUNT(*) FROM sub_modulo_puesto
-- 1.8 unidad_organizacional
SELECT COUNT(*) FROM unidad_organizacional


-- 3. MIN Nomina
SELECT MIN(emp.numero_nomina) AS min_nomina 
FROM empleado_venta emp


-- 4. Mayor antigüedad
SELECT MIN(emp.fecha_ingreso) AS min_ingreso
FROM empleado_venta emp


-- 5. Tipos de unidad organizacional
SELECT COUNT(DISTINCT uo.id_tipo_unidad_organizacional) AS tipos_unidad_organizacional 
FROM unidad_organizacional uo


-- 6. Modulos para 'Especialista de Ingresos'
SELECT mo.id_modulo, mo.descripcion, mo.id_aplicacion, mo.nombre_corto
FROM modulo mo, modulo_puesto mp, puesto_empleado_venta emp 
WHERE mo.id_modulo = mp.id_modulo 
AND emp.descripcion = 'Especialista de Ingresos' 
AND emp.id_puesto_empleado_venta = mp.id_puesto_empleado


-- 7. Sub Modulos para 'Líder de Ventas'
SELECT COUNT(*)
FROM sub_modulo sm, sub_modulo_puesto smp, puesto_empleado_venta emp 
WHERE sm.id_modulo = smp.id_sub_modulo
AND emp.descripcion = 'Líder de Ventas' 
AND emp.id_puesto_empleado_venta = smp.id_puesto_empleado


-- 8. Empleado más joven  (nombre y puesto)
SELECT emp.nombres, pev.descripcion, MAX(emp.fecha_nacimiento) fecha_nacimiento
FROM empleado_venta emp, puesto_empleado_venta pev


-- 9. Agregar registro en aplicacion
INSERT INTO `aplicacion` (`id_aplicacion`, `descripcion`) VALUES
(2, 'Aplicación IoT para conocer la geolocalización de las herramientas móviles del equipo de ventas');


-- 10. Tabla Tipo Unidad Organizacional

CREATE TABLE `tipo_unidad_organizacional` (
  `id_tipo_unidad_organizacional` int(1) NOT NULL,
  `id_unidad_organizacional` int(11) NOT NULL,
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;


ALTER TABLE `tipo_unidad_organizacional`
  ADD PRIMARY KEY (`id_tipo_unidad_organizacional`),
  ADD CONSTRAINT `as_tipo_unidad_organizacional_ibfk_1` 
  FOREIGN KEY (`id_unidad_organizacional`) 
  REFERENCES `unidad_organizacional` (`id_unidad_organizacional`);


INSERT INTO `tipo_unidad_organizacional` (`id_tipo_unidad_organizacional`, `id_unidad_organizacional`) VALUES
(1, 1),
(3, 19),
(4, 61);






