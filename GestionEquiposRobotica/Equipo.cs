using System;

namespace GestionEquiposRobotica
{
    internal class Equipo
    {
        public string Nombre { get; set; }
        public string Institucion { get; set; }
        public string Categoria { get; set; }
        public double Puntaje { get; set; }
        public string Pais { get; set; }

        public Equipo(string nombre, string institucion,
                      string categoria, double puntaje, string pais)
        {
            Nombre = nombre;
            Institucion = institucion;
            Categoria = categoria;
            Puntaje = puntaje;
            Pais = pais;
        }

        public override string ToString()
        {
            return Nombre + " | " +
                   Institucion + " | " +
                   Categoria + " | " +
                   Puntaje + " | " +
                   Pais;
        }
    }
}