using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GestionEquiposRobotica
{
    public partial class Form1 : Form
    {
        Equipo[] equipos = new Equipo[20];
        int contador = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void btnRegistrar_Click(object sender, EventArgs e)
        {
            if (txtPuntaje.Text == "")
            {
                MessageBox.Show("Ingrese un puntaje");
                return;
            }
            if (contador < 20)
            {
                equipos[contador] = new Equipo(
                    txtNombre.Text,
                    txtInstitucion.Text,
                    txtCategoria.Text,
                    double.Parse(txtPuntaje.Text),
                    txtPais.Text
                );

                contador++;

                MessageBox.Show("Equipo registrado");

                txtNombre.Clear();
                txtInstitucion.Clear();
                txtCategoria.Clear();
                txtPuntaje.Clear();
                txtPais.Clear();
            }
            else
            {
                MessageBox.Show("Vector lleno");
            }
        }

        private void btnMostrar_Click(object sender, EventArgs e)
        {
            lstEquipos.Items.Clear();

            for (int i = 0; i < contador; i++)
            {
                lstEquipos.Items.Add(equipos[i]);
            }
            lstEquipos.Items.Clear();

            for (int i = 0; i < contador; i++)
            {
                lstEquipos.Items.Add(equipos[i].ToString());
            }



            {
               
            }
            

            
            {
                
            }



            {
                
            }
            

            
            {
                
            }
        }

        private void btnOrdenar_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < contador - 1; i++)
            {
                for (int j = i + 1; j < contador; j++)
                {
                    if (equipos[i].Puntaje < equipos[j].Puntaje)
                    {
                        Equipo aux = equipos[i];
                        equipos[i] = equipos[j];
                        equipos[j] = aux;
                    }
                }
            }

            MessageBox.Show("Equipos ordenados");

        }

        private void btnMejorPeor_Click(object sender, EventArgs e)
        {
            Equipo mejor = equipos[0];
            Equipo peor = equipos[0];

            for (int i = 1; i < contador; i++)
            {
                if (equipos[i].Puntaje > mejor.Puntaje)
                {
                    mejor = equipos[i];
                }

                if (equipos[i].Puntaje < peor.Puntaje)
                {
                    peor = equipos[i];
                }
            }

            MessageBox.Show(
                "Mejor equipo:\n" + mejor.ToString() +
                "\n\nPeor equipo:\n" + peor.ToString()
            );

        }

        private void btnFiltrar_Click(object sender, EventArgs e)
        {
            lstEquipos.Items.Clear();

            for (int i = 0; i < contador; i++)
            {
                if (equipos[i].Pais.ToLower() ==
                    txtFiltroPais.Text.ToLower())
                {
                    lstEquipos.Items.Add(equipos[i].ToString());
                }
            }

        }

        private void btnContar_Click(object sender, EventArgs e)
        {
            if (txtPuntajeMinimo.Text == "")
            {
                MessageBox.Show("Ingrese un puntaje mínimo");
                return;
            }

            int cantidad = 0;
            double minimo = double.Parse(txtPuntajeMinimo.Text);

            for (int i = 0; i < contador; i++)
            {
                if (equipos[i].Pais.ToLower() == "republica dominicana"
                    && equipos[i].Puntaje > minimo)
                {
                    cantidad++;
                }
            }

            MessageBox.Show(
                "Equipos nacionales que superan el puntaje: " +
                cantidad
            );

            {
                
            }
            
            {
                
                  
                {
                  
                }
            }

            
                
          
            

        }
    }
}
