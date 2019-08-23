/*
 * =====================================================================================
 *
 *       Filename:  LibroCalificaciones.cpp
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

#include "LibroCalificaciones.h"
#include <iomanip>
#include <iostream>

LibroCalificaciones::LibroCalificaciones(){}

LibroCalificaciones::LibroCalificaciones(const std::string& nombreCurso, int arregloCalificaciones[][EXAMENES]) {

	setNombreCurso(nombreCurso);

	for (int estudiante = 0; estudiante < ESTUDIANTES; ++estudiante) {
		for (int examen = 0; examen < EXAMENES; ++examen) {
			calificaciones[estudiante][examen] = arregloCalificaciones[estudiante][examen];
		}
	}
}

int LibroCalificaciones::obtenerNotaMaxima() {

	int NotaMaxima = 0;

	for (int estudiante = 0; estudiante < ESTUDIANTES; ++estudiante) {
		for (int examen = 0; examen < EXAMENES; ++examen) {
			if (calificaciones[estudiante][examen] > NotaMaxima) {
				NotaMaxima = calificaciones[estudiante][examen];
			}
		}
	}
	return NotaMaxima;
}

int LibroCalificaciones::obtenerNotaMinima() {
	
	int NotaMinima = 100;

	for (int estudiante = 0; estudiante < ESTUDIANTES; ++estudiante) {
		for (int examen = 0; examen < EXAMENES; ++examen) {
			if (calificaciones[estudiante][examen] < NotaMinima) {
				NotaMinima = calificaciones[estudiante][examen];
			}
		}
	}
	return NotaMinima;
}

double LibroCalificaciones::obtenerPromedio(const int estudi, const int exam){

	double Promedio;
	double Sum = 0;

	for (int examen = 0; examen < exam; examen++) {
		Sum = Sum + calificaciones[estudi][examen];
	}

	Promedio = Sum / EXAMENES;
	return Promedio;
}

std::string LibroCalificaciones::obtenerReporteNotaMaxMin(){

	std::string reporteMaxMin = "";

	reporteMaxMin = "\nLa nota minima es: [" + std::to_string(obtenerNotaMinima()) + "]\nLa nota maxima es: ["
		      + std::to_string(obtenerNotaMaxima()) + "]\n";

	return reporteMaxMin;
}

std::string LibroCalificaciones::obtenerReporteNotas(){

	std::string reporteNotas = "";
	std::string descripcion = "\nLas siguientes son las notas del curso ["
		                     + getNombreCurso() + "]: \n\t\t\t\tExamen 1\tExamen 2\tExamen 3\tPromedio";

	for (int estudiante = 0; estudiante < ESTUDIANTES; ++estudiante) {

		int est = estudiante;
		reporteNotas = reporteNotas + "\nEstudiante [" + std::to_string(estudiante) + "]\t\t\t"
			                        + std::to_string(calificaciones[estudiante][0]) + "\t\t"
			                        + std::to_string(calificaciones[estudiante][1]) + "\t\t"
			                        + std::to_string(calificaciones[estudiante][2]) + "\t\t"
			                        + std::to_string(obtenerPromedio(estudiante, 3)) + "";
	}

	return descripcion + reporteNotas;
}

const std::string LibroCalificaciones::getNombreCurso(){

	return nombreCurso;
}

void LibroCalificaciones::setNombreCurso(const std::string &nomCur){

	LibroCalificaciones::nombreCurso = nomCur;
}