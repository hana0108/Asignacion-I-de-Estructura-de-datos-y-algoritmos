namespace GestionEquiposRobotica
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.txtNombre = new System.Windows.Forms.TextBox();
            this.txtInstitucion = new System.Windows.Forms.TextBox();
            this.txtCategoria = new System.Windows.Forms.TextBox();
            this.txtPuntaje = new System.Windows.Forms.TextBox();
            this.txtPais = new System.Windows.Forms.TextBox();
            this.btnRegistrar = new System.Windows.Forms.Button();
            this.lstEquipos = new System.Windows.Forms.ListBox();
            this.btnMostrar = new System.Windows.Forms.Button();
            this.btnOrdenar = new System.Windows.Forms.Button();
            this.btnMejorPeor = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.txtFiltroPais = new System.Windows.Forms.TextBox();
            this.btnFiltrar = new System.Windows.Forms.Button();
            this.btnContar = new System.Windows.Forms.Button();
            this.label7 = new System.Windows.Forms.Label();
            this.txtPuntajeMinimo = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(36, 40);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(65, 20);
            this.label1.TabIndex = 0;
            this.label1.Text = "Nombre";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(36, 103);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(82, 20);
            this.label2.TabIndex = 1;
            this.label2.Text = "Institución";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(36, 163);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(78, 20);
            this.label3.TabIndex = 2;
            this.label3.Text = "Categoría";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(36, 226);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(63, 20);
            this.label4.TabIndex = 3;
            this.label4.Text = "Puntaje";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(36, 285);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(39, 20);
            this.label5.TabIndex = 4;
            this.label5.Text = "País";
            // 
            // txtNombre
            // 
            this.txtNombre.Location = new System.Drawing.Point(107, 37);
            this.txtNombre.Name = "txtNombre";
            this.txtNombre.Size = new System.Drawing.Size(100, 26);
            this.txtNombre.TabIndex = 5;
            // 
            // txtInstitucion
            // 
            this.txtInstitucion.Location = new System.Drawing.Point(124, 100);
            this.txtInstitucion.Name = "txtInstitucion";
            this.txtInstitucion.Size = new System.Drawing.Size(100, 26);
            this.txtInstitucion.TabIndex = 6;
            // 
            // txtCategoria
            // 
            this.txtCategoria.Location = new System.Drawing.Point(120, 163);
            this.txtCategoria.Name = "txtCategoria";
            this.txtCategoria.Size = new System.Drawing.Size(100, 26);
            this.txtCategoria.TabIndex = 7;
            // 
            // txtPuntaje
            // 
            this.txtPuntaje.Location = new System.Drawing.Point(105, 223);
            this.txtPuntaje.Name = "txtPuntaje";
            this.txtPuntaje.Size = new System.Drawing.Size(100, 26);
            this.txtPuntaje.TabIndex = 8;
            // 
            // txtPais
            // 
            this.txtPais.Location = new System.Drawing.Point(81, 282);
            this.txtPais.Name = "txtPais";
            this.txtPais.Size = new System.Drawing.Size(100, 26);
            this.txtPais.TabIndex = 9;
            // 
            // btnRegistrar
            // 
            this.btnRegistrar.Location = new System.Drawing.Point(292, 27);
            this.btnRegistrar.Name = "btnRegistrar";
            this.btnRegistrar.Size = new System.Drawing.Size(92, 32);
            this.btnRegistrar.TabIndex = 10;
            this.btnRegistrar.Text = "Registrar";
            this.btnRegistrar.UseVisualStyleBackColor = true;
            this.btnRegistrar.Click += new System.EventHandler(this.btnRegistrar_Click);
            // 
            // lstEquipos
            // 
            this.lstEquipos.FormattingEnabled = true;
            this.lstEquipos.ItemHeight = 20;
            this.lstEquipos.Location = new System.Drawing.Point(448, 27);
            this.lstEquipos.Name = "lstEquipos";
            this.lstEquipos.Size = new System.Drawing.Size(340, 204);
            this.lstEquipos.TabIndex = 11;
            // 
            // btnMostrar
            // 
            this.btnMostrar.Location = new System.Drawing.Point(292, 103);
            this.btnMostrar.Name = "btnMostrar";
            this.btnMostrar.Size = new System.Drawing.Size(150, 33);
            this.btnMostrar.TabIndex = 12;
            this.btnMostrar.Text = "Mostrar Equipos";
            this.btnMostrar.UseVisualStyleBackColor = true;
            this.btnMostrar.Click += new System.EventHandler(this.btnMostrar_Click);
            // 
            // btnOrdenar
            // 
            this.btnOrdenar.Location = new System.Drawing.Point(292, 142);
            this.btnOrdenar.Name = "btnOrdenar";
            this.btnOrdenar.Size = new System.Drawing.Size(138, 41);
            this.btnOrdenar.TabIndex = 13;
            this.btnOrdenar.Text = "Ordenar Puntaje";
            this.btnOrdenar.UseVisualStyleBackColor = true;
            this.btnOrdenar.Click += new System.EventHandler(this.btnOrdenar_Click);
            // 
            // btnMejorPeor
            // 
            this.btnMejorPeor.Location = new System.Drawing.Point(292, 65);
            this.btnMejorPeor.Name = "btnMejorPeor";
            this.btnMejorPeor.Size = new System.Drawing.Size(112, 32);
            this.btnMejorPeor.TabIndex = 14;
            this.btnMejorPeor.Text = "Mejor y Peor";
            this.btnMejorPeor.UseVisualStyleBackColor = true;
            this.btnMejorPeor.Click += new System.EventHandler(this.btnMejorPeor_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(36, 329);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(83, 20);
            this.label6.TabIndex = 15;
            this.label6.Text = "Filtrar País";
            // 
            // txtFiltroPais
            // 
            this.txtFiltroPais.Location = new System.Drawing.Point(125, 326);
            this.txtFiltroPais.Name = "txtFiltroPais";
            this.txtFiltroPais.Size = new System.Drawing.Size(100, 26);
            this.txtFiltroPais.TabIndex = 16;
            // 
            // btnFiltrar
            // 
            this.btnFiltrar.Location = new System.Drawing.Point(292, 190);
            this.btnFiltrar.Name = "btnFiltrar";
            this.btnFiltrar.Size = new System.Drawing.Size(75, 39);
            this.btnFiltrar.TabIndex = 17;
            this.btnFiltrar.Text = "Filtrar";
            this.btnFiltrar.UseVisualStyleBackColor = true;
            this.btnFiltrar.Click += new System.EventHandler(this.btnFiltrar_Click);
            // 
            // btnContar
            // 
            this.btnContar.Location = new System.Drawing.Point(292, 235);
            this.btnContar.Name = "btnContar";
            this.btnContar.Size = new System.Drawing.Size(151, 37);
            this.btnContar.TabIndex = 19;
            this.btnContar.Text = "Contar Nacionales";
            this.btnContar.UseVisualStyleBackColor = true;
            this.btnContar.Click += new System.EventHandler(this.btnContar_Click);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(500, 243);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(117, 20);
            this.label7.TabIndex = 20;
            this.label7.Text = "Puntaje mínimo";
            // 
            // txtPuntajeMinimo
            // 
            this.txtPuntajeMinimo.Location = new System.Drawing.Point(623, 240);
            this.txtPuntajeMinimo.Name = "txtPuntajeMinimo";
            this.txtPuntajeMinimo.Size = new System.Drawing.Size(100, 26);
            this.txtPuntajeMinimo.TabIndex = 21;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(609, 402);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(146, 20);
            this.label8.TabIndex = 22;
            this.label8.Text = "Autor: Daniel Perez";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.txtPuntajeMinimo);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.btnContar);
            this.Controls.Add(this.btnFiltrar);
            this.Controls.Add(this.txtFiltroPais);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.btnMejorPeor);
            this.Controls.Add(this.btnOrdenar);
            this.Controls.Add(this.btnMostrar);
            this.Controls.Add(this.lstEquipos);
            this.Controls.Add(this.btnRegistrar);
            this.Controls.Add(this.txtPais);
            this.Controls.Add(this.txtPuntaje);
            this.Controls.Add(this.txtCategoria);
            this.Controls.Add(this.txtInstitucion);
            this.Controls.Add(this.txtNombre);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox txtNombre;
        private System.Windows.Forms.TextBox txtInstitucion;
        private System.Windows.Forms.TextBox txtCategoria;
        private System.Windows.Forms.TextBox txtPuntaje;
        private System.Windows.Forms.TextBox txtPais;
        private System.Windows.Forms.Button btnRegistrar;
        private System.Windows.Forms.ListBox lstEquipos;
        private System.Windows.Forms.Button btnMostrar;
        private System.Windows.Forms.Button btnOrdenar;
        private System.Windows.Forms.Button btnMejorPeor;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox txtFiltroPais;
        private System.Windows.Forms.Button btnFiltrar;
        private System.Windows.Forms.Button btnContar;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox txtPuntajeMinimo;
        private System.Windows.Forms.Label label8;
    }
}

