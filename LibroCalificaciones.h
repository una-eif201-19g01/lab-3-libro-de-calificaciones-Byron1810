/*
 * =====================================================================================
 *
 *       Filename:  LibroCalificaciones.h
 *
 *    Description:  Reporte de calificaciones
 *
 *        Created:  2019-08-16
 *
 *         Author:  Byron Argüello Rodríguez byron181098@gmail.com
 *   Organization:  Universidad Nacional de Costa Rica
 *
 * =====================================================================================
 */


#ifndef CALIFICACIONES_LIBROCALIFICACIONES_H
#define CALIFICACIONES_LIBROCALIFICACIONES_H

#include <string>

static const int ESTUDIANTES = 10;
static const int EXAMENES = 3;

class LibroCalificaciones {
	
private:

	std::string nombreCurso;
	int calificaciones[ESTUDIANTES][EXAMENES];

	int obtenerNotaMinima();
	int obtenerNotaMaxima();
	double obtenerPromedio(const int, const int);

public:

    LibroCalificaciones();
	LibroCalificaciones(const std::string &nombreCurso, int [][EXAMENES]);

	std::string obtenerReporteNotas();
	std::string obtenerReporteNotaMaxMin();

	const std::string getNombreCurso();
	void setNombreCurso(const std::string &nombreCurso);
	
};


#endif //CALIFICACIONES_LIBROCALIFICACIONES_H
