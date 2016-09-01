Public Class Form1
    Dim pointer As Integer = 0
    Dim diag As Boolean = False
    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Dim Coms() As String = IO.Ports.SerialPort.GetPortNames()
        For Each Port In Coms
            CB1.Items.Add(Port)
        Next
    End Sub

    Private Sub btn_select_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btn_select.Click
        SP1.PortName = CB1.SelectedItem.ToString
        SP1.BaudRate = 38400
        SP1.Handshake = IO.Ports.Handshake.None
        SP1.StopBits = IO.Ports.StopBits.One
        SP1.DtrEnable = True
        SP1.DataBits = 8
        SP1.Open()

        If SP1.IsOpen Then
            CB1.Enabled = False
            btn_select.Enabled = False
        End If
    End Sub

    Private Sub CB1_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CB1.SelectedIndexChanged
        If CB1.SelectedItem.ToString <> "" Then
            btn_select.Enabled = True
        Else
            btn_select.Enabled = False
        End If
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btn_test.Click
        For Each series In Chart1.Series
            series.Points.Clear()
        Next
        pointer = 0
        ListBox1.Items.Clear()

        'SP1.Close()
        'SP1.Open()
    End Sub
    Public Delegate Sub get_Serial(ByVal value As String)

    Dim euler(10) As Double

    Sub get_Serial_sub(ByVal data As String)
            ListBox1.Items.Add(data)
            ListBox1.SelectedIndex = ListBox1.Items.Count - 1
            Dim s As String()
            s = data.Split(vbTab)
            If s(0).StartsWith("M") Then
                For i = 1 To s.Length - 1
                    euler(i) = s(i)
                Chart2.Series(i - 1).Points.AddY(euler(i))
                Next
            Else
                For i = 1 To s.Length - 1
                    euler(i) = s(i)
                Chart1.Series(i - 1).Points.AddY(euler(i))
                Next
            End If

            Label1.Text = SP1.BytesToRead()
            If Chart1.Series(0).Points.Count > auto_reset.Value Then
                For Each series In Chart1.Series
                    If series.Points.Count > 0 Then
                        series.Points.RemoveAt(0)
                    End If
                Next
            End If
            If Chart2.Series(0).Points.Count > auto_reset.Value Then
                For Each series In Chart2.Series
                    If series.Points.Count > 0 Then
                        series.Points.RemoveAt(0)
                    End If
                Next
            End If
    End Sub

    Private Sub SP1_DataReceived(ByVal sender As Object, ByVal e As System.IO.Ports.SerialDataReceivedEventArgs) Handles SP1.DataReceived
        Dim gs As New get_Serial(AddressOf Me.get_Serial_sub)
        Me.Invoke(gs, SP1.ReadLine())
        'Chart1.Series(0).Points.RemoveAt(0)
    End Sub

    Private Sub btn_get_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btn_get.Click
        SP1.Write("a")
        SP1.ReceivedBytesThreshold = 1
    End Sub

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        SP1.WriteLine("a")
    End Sub

    Private Sub btn_Auto_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btn_Auto.Click
        Timer1.Enabled = Not Timer1.Enabled
    End Sub

    Private Sub NumericUpDown1_ValueChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles NumericUpDown1.ValueChanged
        Timer1.Interval = NumericUpDown1.Value
    End Sub

    Private Sub Button1_Click_1(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Chart1.ChartAreas(0).AxisY.Minimum = -180 * 16
        Chart1.ChartAreas(0).AxisY.Maximum = 180 * 16
        Chart1.ChartAreas(0).AxisY.Interval = 30 * 16
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        SP1.DiscardInBuffer()
    End Sub
End Class
