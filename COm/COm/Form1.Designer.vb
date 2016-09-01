<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Das Formular überschreibt den Löschvorgang, um die Komponentenliste zu bereinigen.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Wird vom Windows Form-Designer benötigt.
    Private components As System.ComponentModel.IContainer

    'Hinweis: Die folgende Prozedur ist für den Windows Form-Designer erforderlich.
    'Das Bearbeiten ist mit dem Windows Form-Designer möglich.  
    'Das Bearbeiten mit dem Code-Editor ist nicht möglich.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Dim ChartArea1 As System.Windows.Forms.DataVisualization.Charting.ChartArea = New System.Windows.Forms.DataVisualization.Charting.ChartArea()
        Dim Legend1 As System.Windows.Forms.DataVisualization.Charting.Legend = New System.Windows.Forms.DataVisualization.Charting.Legend()
        Dim Series1 As System.Windows.Forms.DataVisualization.Charting.Series = New System.Windows.Forms.DataVisualization.Charting.Series()
        Dim Series2 As System.Windows.Forms.DataVisualization.Charting.Series = New System.Windows.Forms.DataVisualization.Charting.Series()
        Dim Series3 As System.Windows.Forms.DataVisualization.Charting.Series = New System.Windows.Forms.DataVisualization.Charting.Series()
        Dim ChartArea2 As System.Windows.Forms.DataVisualization.Charting.ChartArea = New System.Windows.Forms.DataVisualization.Charting.ChartArea()
        Dim Legend2 As System.Windows.Forms.DataVisualization.Charting.Legend = New System.Windows.Forms.DataVisualization.Charting.Legend()
        Dim Series4 As System.Windows.Forms.DataVisualization.Charting.Series = New System.Windows.Forms.DataVisualization.Charting.Series()
        Dim Series5 As System.Windows.Forms.DataVisualization.Charting.Series = New System.Windows.Forms.DataVisualization.Charting.Series()
        Dim Series6 As System.Windows.Forms.DataVisualization.Charting.Series = New System.Windows.Forms.DataVisualization.Charting.Series()
        Dim Series7 As System.Windows.Forms.DataVisualization.Charting.Series = New System.Windows.Forms.DataVisualization.Charting.Series()
        Me.SP1 = New System.IO.Ports.SerialPort(Me.components)
        Me.CB1 = New System.Windows.Forms.ComboBox()
        Me.btn_select = New System.Windows.Forms.Button()
        Me.Chart1 = New System.Windows.Forms.DataVisualization.Charting.Chart()
        Me.btn_test = New System.Windows.Forms.Button()
        Me.btn_get = New System.Windows.Forms.Button()
        Me.btn_Auto = New System.Windows.Forms.Button()
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.NumericUpDown1 = New System.Windows.Forms.NumericUpDown()
        Me.ListBox1 = New System.Windows.Forms.ListBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.auto_reset = New System.Windows.Forms.NumericUpDown()
        Me.Button1 = New System.Windows.Forms.Button()
        Me.Chart2 = New System.Windows.Forms.DataVisualization.Charting.Chart()
        Me.Button2 = New System.Windows.Forms.Button()
        CType(Me.Chart1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.NumericUpDown1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.auto_reset, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Chart2, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'SP1
        '
        Me.SP1.ReadBufferSize = 40960
        '
        'CB1
        '
        Me.CB1.FormattingEnabled = True
        Me.CB1.Location = New System.Drawing.Point(13, 13)
        Me.CB1.Name = "CB1"
        Me.CB1.Size = New System.Drawing.Size(196, 21)
        Me.CB1.TabIndex = 0
        '
        'btn_select
        '
        Me.btn_select.Enabled = False
        Me.btn_select.Location = New System.Drawing.Point(215, 13)
        Me.btn_select.Name = "btn_select"
        Me.btn_select.Size = New System.Drawing.Size(57, 23)
        Me.btn_select.TabIndex = 1
        Me.btn_select.Text = "Select"
        Me.btn_select.UseVisualStyleBackColor = True
        '
        'Chart1
        '
        Me.Chart1.Anchor = CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
                    Or System.Windows.Forms.AnchorStyles.Left) _
                    Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        ChartArea1.AxisY.Interval = 480.0R
        ChartArea1.AxisY.IsStartedFromZero = False
        ChartArea1.AxisY.MajorGrid.Enabled = False
        ChartArea1.AxisY.Maximum = 2880.0R
        ChartArea1.AxisY.Minimum = -2880.0R
        ChartArea1.Name = "ChartArea1"
        Me.Chart1.ChartAreas.Add(ChartArea1)
        Legend1.Name = "Legend1"
        Me.Chart1.Legends.Add(Legend1)
        Me.Chart1.Location = New System.Drawing.Point(12, 69)
        Me.Chart1.Name = "Chart1"
        Series1.ChartArea = "ChartArea1"
        Series1.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line
        Series1.Legend = "Legend1"
        Series1.Name = "P"
        Series2.ChartArea = "ChartArea1"
        Series2.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line
        Series2.Legend = "Legend1"
        Series2.Name = "R"
        Series3.ChartArea = "ChartArea1"
        Series3.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line
        Series3.Legend = "Legend1"
        Series3.Name = "H"
        Me.Chart1.Series.Add(Series1)
        Me.Chart1.Series.Add(Series2)
        Me.Chart1.Series.Add(Series3)
        Me.Chart1.Size = New System.Drawing.Size(803, 303)
        Me.Chart1.TabIndex = 2
        Me.Chart1.Text = "Chart1"
        '
        'btn_test
        '
        Me.btn_test.Location = New System.Drawing.Point(12, 40)
        Me.btn_test.Name = "btn_test"
        Me.btn_test.Size = New System.Drawing.Size(96, 23)
        Me.btn_test.TabIndex = 3
        Me.btn_test.Text = "Reset Diagram"
        Me.btn_test.UseVisualStyleBackColor = True
        '
        'btn_get
        '
        Me.btn_get.Location = New System.Drawing.Point(114, 40)
        Me.btn_get.Name = "btn_get"
        Me.btn_get.Size = New System.Drawing.Size(65, 23)
        Me.btn_get.TabIndex = 4
        Me.btn_get.Text = "Get Data"
        Me.btn_get.UseVisualStyleBackColor = True
        '
        'btn_Auto
        '
        Me.btn_Auto.Location = New System.Drawing.Point(185, 40)
        Me.btn_Auto.Name = "btn_Auto"
        Me.btn_Auto.Size = New System.Drawing.Size(42, 23)
        Me.btn_Auto.TabIndex = 5
        Me.btn_Auto.Text = "Auto"
        Me.btn_Auto.UseVisualStyleBackColor = True
        '
        'Timer1
        '
        Me.Timer1.Interval = 500
        '
        'NumericUpDown1
        '
        Me.NumericUpDown1.Increment = New Decimal(New Integer() {10, 0, 0, 0})
        Me.NumericUpDown1.Location = New System.Drawing.Point(234, 40)
        Me.NumericUpDown1.Maximum = New Decimal(New Integer() {10000, 0, 0, 0})
        Me.NumericUpDown1.Minimum = New Decimal(New Integer() {1, 0, 0, 0})
        Me.NumericUpDown1.Name = "NumericUpDown1"
        Me.NumericUpDown1.Size = New System.Drawing.Size(38, 20)
        Me.NumericUpDown1.TabIndex = 6
        Me.NumericUpDown1.Value = New Decimal(New Integer() {100, 0, 0, 0})
        '
        'ListBox1
        '
        Me.ListBox1.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
                    Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.ListBox1.FormattingEnabled = True
        Me.ListBox1.Location = New System.Drawing.Point(821, 7)
        Me.ListBox1.Name = "ListBox1"
        Me.ListBox1.Size = New System.Drawing.Size(227, 732)
        Me.ListBox1.TabIndex = 8
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(288, 18)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(39, 13)
        Me.Label1.TabIndex = 9
        Me.Label1.Text = "Label1"
        '
        'auto_reset
        '
        Me.auto_reset.Increment = New Decimal(New Integer() {10, 0, 0, 0})
        Me.auto_reset.Location = New System.Drawing.Point(278, 40)
        Me.auto_reset.Maximum = New Decimal(New Integer() {10000, 0, 0, 0})
        Me.auto_reset.Minimum = New Decimal(New Integer() {1, 0, 0, 0})
        Me.auto_reset.Name = "auto_reset"
        Me.auto_reset.Size = New System.Drawing.Size(38, 20)
        Me.auto_reset.TabIndex = 11
        Me.auto_reset.Value = New Decimal(New Integer() {100, 0, 0, 0})
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(335, 37)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(96, 23)
        Me.Button1.TabIndex = 12
        Me.Button1.Text = "Reset Scale"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'Chart2
        '
        Me.Chart2.Anchor = CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
                    Or System.Windows.Forms.AnchorStyles.Left) _
                    Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        ChartArea2.AxisY.Interval = 250.0R
        ChartArea2.AxisY.IsStartedFromZero = False
        ChartArea2.AxisY.MajorGrid.Enabled = False
        ChartArea2.AxisY.Maximum = 3750.0R
        ChartArea2.AxisY.Minimum = -3750.0R
        ChartArea2.Name = "ChartArea1"
        Me.Chart2.ChartAreas.Add(ChartArea2)
        Legend2.Name = "Legend1"
        Me.Chart2.Legends.Add(Legend2)
        Me.Chart2.Location = New System.Drawing.Point(12, 378)
        Me.Chart2.Name = "Chart2"
        Series4.ChartArea = "ChartArea1"
        Series4.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line
        Series4.Legend = "Legend1"
        Series4.Name = "FL"
        Series5.ChartArea = "ChartArea1"
        Series5.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line
        Series5.Legend = "Legend1"
        Series5.Name = "FR"
        Series6.ChartArea = "ChartArea1"
        Series6.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line
        Series6.Legend = "Legend1"
        Series6.Name = "BL"
        Series7.ChartArea = "ChartArea1"
        Series7.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line
        Series7.Legend = "Legend1"
        Series7.Name = "BR"
        Me.Chart2.Series.Add(Series4)
        Me.Chart2.Series.Add(Series5)
        Me.Chart2.Series.Add(Series6)
        Me.Chart2.Series.Add(Series7)
        Me.Chart2.Size = New System.Drawing.Size(803, 371)
        Me.Chart2.TabIndex = 13
        Me.Chart2.Text = "Chart2"
        '
        'Button2
        '
        Me.Button2.Location = New System.Drawing.Point(335, 13)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(96, 23)
        Me.Button2.TabIndex = 14
        Me.Button2.Text = "Reset Scale"
        Me.Button2.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(1060, 756)
        Me.Controls.Add(Me.Button2)
        Me.Controls.Add(Me.Chart2)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.auto_reset)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.ListBox1)
        Me.Controls.Add(Me.NumericUpDown1)
        Me.Controls.Add(Me.btn_Auto)
        Me.Controls.Add(Me.btn_get)
        Me.Controls.Add(Me.btn_test)
        Me.Controls.Add(Me.Chart1)
        Me.Controls.Add(Me.btn_select)
        Me.Controls.Add(Me.CB1)
        Me.Name = "Form1"
        Me.Text = "Drohne"
        CType(Me.Chart1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.NumericUpDown1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.auto_reset, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Chart2, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents SP1 As System.IO.Ports.SerialPort
    Friend WithEvents CB1 As System.Windows.Forms.ComboBox
    Friend WithEvents btn_select As System.Windows.Forms.Button
    Friend WithEvents Chart1 As System.Windows.Forms.DataVisualization.Charting.Chart
    Friend WithEvents btn_test As System.Windows.Forms.Button
    Friend WithEvents btn_get As System.Windows.Forms.Button
    Friend WithEvents btn_Auto As System.Windows.Forms.Button
    Friend WithEvents Timer1 As System.Windows.Forms.Timer
    Friend WithEvents NumericUpDown1 As System.Windows.Forms.NumericUpDown
    Friend WithEvents ListBox1 As System.Windows.Forms.ListBox
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents auto_reset As System.Windows.Forms.NumericUpDown
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents Chart2 As System.Windows.Forms.DataVisualization.Charting.Chart
    Friend WithEvents Button2 As System.Windows.Forms.Button

End Class
