object Form1: TForm1
  Left = 0
  Top = 0
  AutoSize = True
  Caption = #51648#49688#47196#44536'(by '#44608#51648#54984')'
  ClientHeight = 380
  ClientWidth = 514
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Visible = True
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 15
  object Label9: TLabel
    Left = 388
    Top = 8
    Width = 126
    Height = 13
    Caption = 'made by Kim Jihoon'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'SimSun-ExtB'
    Font.Style = []
    ParentFont = False
  end
  object Label10: TLabel
    Left = 259
    Top = 8
    Width = 51
    Height = 15
    Caption = #54632#49688' '#44405#44592
  end
  object ComboBox1: TComboBox
    Left = 0
    Top = 0
    Width = 145
    Height = 23
    TabOrder = 0
    Text = #51648#49688#47196#44536
    OnChange = ComboBox1Change
    Items.Strings = (
      #51648#49688#47196#44536
      #49340#44033#54632#49688)
  end
  object Panel2: TPanel
    Left = 249
    Top = 32
    Width = 265
    Height = 348
    TabOrder = 1
    object Image1: TImage
      Left = 7
      Top = 56
      Width = 250
      Height = 250
    end
    object Label2: TLabel
      Left = 16
      Top = 7
      Width = 51
      Height = 15
      Caption = #51340#54364#52629' '#49353
    end
    object Label3: TLabel
      Left = 95
      Top = 7
      Width = 39
      Height = 15
      Caption = #54632#49688' '#49353
    end
    object Label8: TLabel
      Left = 183
      Top = 7
      Width = 53
      Height = 15
      Caption = #54632#49688' scale'
    end
    object ColorBox1: TColorBox
      Left = 8
      Top = 28
      Width = 81
      Height = 22
      TabOrder = 0
      OnChange = ColorBox1Change
    end
    object ColorBox2: TColorBox
      Left = 95
      Top = 28
      Width = 82
      Height = 22
      DefaultColorColor = clBlue
      NoneColorColor = clBlue
      Selected = clBlue
      TabOrder = 1
      OnChange = ColorBox2Change
    end
    object Button5: TButton
      Left = 8
      Top = 312
      Width = 75
      Height = 25
      Caption = #52488#44592#54868
      TabOrder = 2
      OnClick = FormShow
    end
    object Button6: TButton
      Left = 89
      Top = 312
      Width = 72
      Height = 25
      Caption = #51200#51109
      TabOrder = 3
      OnClick = Button6Click
    end
    object Edit14: TEdit
      Left = 183
      Top = 27
      Width = 74
      Height = 23
      TabOrder = 4
      Text = '5'
      OnExit = Edit14Exit
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 272
    Width = 243
    Height = 108
    TabOrder = 2
    object Label4: TLabel
      Left = 17
      Top = 15
      Width = 82
      Height = 15
      Caption = #48120#51648#49688' '#46020#44396
    end
    object Label5: TLabel
      Left = 33
      Top = 41
      Width = 18
      Height = 23
      Caption = 'x'#44050
    end
    object Label7: TLabel
      Left = 33
      Top = 108
      Width = 18
      Height = 15
      Caption = 'y'#44050
      Visible = False
    end
    object TrackBar1: TTrackBar
      Left = 13
      Top = 65
      Width = 224
      Height = 45
      Max = 1000
      TabOrder = 0
      OnChange = TrackBar1Change
    end
    object Edit4: TEdit
      Left = 105
      Top = 37
      Width = 63
      Height = 23
      TabOrder = 1
      TextHint = #52572#49548#44050
      OnExit = Edit4Exit
    end
    object Edit5: TEdit
      Left = 174
      Top = 37
      Width = 63
      Height = 23
      TabOrder = 2
      TextHint = #52572#45824#44050
      OnExit = Edit5Exit
    end
    object TrackBar2: TTrackBar
      Left = 17
      Top = 132
      Width = 224
      Height = 45
      TabOrder = 3
      Visible = False
      OnChange = TrackBar2Change
    end
    object Edit8: TEdit
      Left = 105
      Top = 103
      Width = 63
      Height = 23
      NumbersOnly = True
      TabOrder = 4
      TextHint = #52572#49548#44050
      Visible = False
      OnExit = Edit8Exit
    end
    object Edit9: TEdit
      Left = 174
      Top = 103
      Width = 63
      Height = 23
      NumbersOnly = True
      TabOrder = 5
      TextHint = #52572#45824#44050
      Visible = False
      OnExit = Edit9Exit
    end
    object Edit12: TEdit
      Left = 57
      Top = 37
      Width = 42
      Height = 23
      TabOrder = 6
      TextHint = #44050
      OnExit = Edit12Exit
    end
    object Edit13: TEdit
      Left = 56
      Top = 104
      Width = 43
      Height = 23
      TabOrder = 7
      TextHint = #44050
      Visible = False
      OnExit = Edit13Exit
    end
    object ComboBox2: TComboBox
      Left = 105
      Top = 8
      Width = 133
      Height = 23
      TabOrder = 8
      Text = #49892#49884#44036' '#44228#49328'X'
      Items.Strings = (
        #49892#49884#44036' '#44228#49328'X'
        #51648#49688#54632#49688
        #47196#44536#54632#49688
        #49340#44033#54632#49688)
    end
  end
  object CheckBox2: TCheckBox
    Left = 159
    Top = 0
    Width = 97
    Height = 17
    Caption = #51088#52712' '#45224#44592#44592
    Checked = True
    State = cbChecked
    TabOrder = 3
    OnClick = CheckBox2Click
  end
  object Edit6: TEdit
    Left = 17
    Top = 141
    Width = 72
    Height = 23
    HelpType = htKeyword
    TabOrder = 4
    TextHint = #48145
  end
  object Edit7: TEdit
    Left = 86
    Top = 141
    Width = 67
    Height = 23
    TabOrder = 5
    TextHint = #51652#49688
  end
  object Panel1: TPanel
    Left = 0
    Top = 29
    Width = 243
    Height = 228
    TabOrder = 6
    object Label1: TLabel
      Left = 17
      Top = 8
      Width = 51
      Height = 15
      Caption = #51648#49688' '#46020#44396
    end
    object Label6: TLabel
      Left = 17
      Top = 62
      Width = 51
      Height = 15
      Caption = #47196#44536' '#46020#44396
    end
    object Label11: TLabel
      Left = 16
      Top = 144
      Width = 75
      Height = 15
      Caption = #49340#44033#54632#49688' '#46020#44396
    end
    object Edit1: TEdit
      Left = 17
      Top = 29
      Width = 72
      Height = 23
      HelpType = htKeyword
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      TextHint = #48145
    end
    object Button1: TButton
      Left = 167
      Top = 8
      Width = 42
      Height = 44
      Caption = #44228#49328
      TabOrder = 1
      OnClick = Button1Click
    end
    object Edit2: TEdit
      Left = 86
      Top = 29
      Width = 75
      Height = 23
      TabOrder = 2
      TextHint = #51648#49688
    end
    object Edit3: TEdit
      Left = 17
      Top = 194
      Width = 208
      Height = 23
      TabOrder = 3
      TextHint = #44208#44284
    end
    object Edit10: TEdit
      Left = 17
      Top = 83
      Width = 72
      Height = 23
      HelpType = htKeyword
      TabOrder = 4
      TextHint = #48145
    end
    object Edit11: TEdit
      Left = 86
      Top = 83
      Width = 75
      Height = 23
      TabOrder = 5
      TextHint = #51652#49688
    end
    object Button2: TButton
      Left = 167
      Top = 58
      Width = 42
      Height = 71
      Caption = #44228#49328
      TabOrder = 6
      OnClick = Button2Click
    end
    object CheckBox5: TCheckBox
      Left = 16
      Top = 112
      Width = 128
      Height = 17
      Caption = #51088#50672#47196#44536' '#44228#49328#54616#44592
      TabOrder = 7
      OnClick = CheckBox5Click
    end
    object Edit16: TEdit
      Left = 48
      Top = 165
      Width = 41
      Height = 23
      TabOrder = 8
      TextHint = #44033#46020
    end
    object Button3: TButton
      Left = 207
      Top = 8
      Width = 27
      Height = 44
      BiDiMode = bdLeftToRight
      Caption = #44536#47532#44592
      ParentBiDiMode = False
      TabOrder = 9
      WordWrap = True
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 207
      Top = 58
      Width = 27
      Height = 71
      Caption = #44536#47532#44592
      TabOrder = 10
      WordWrap = True
      OnClick = Button4Click
    end
    object ComboBox3: TComboBox
      Left = 86
      Top = 165
      Width = 75
      Height = 23
      ItemIndex = 0
      TabOrder = 11
      Text = 'sin('#49324#51064')'
      Items.Strings = (
        'sin('#49324#51064')'
        'cos('#53076#49324#51064')'
        'tan('#53444#51232#53944')')
    end
    object Button7: TButton
      Left = 167
      Top = 144
      Width = 42
      Height = 44
      Caption = #44228#49328
      TabOrder = 12
      OnClick = Button7Click
    end
    object Button8: TButton
      Left = 207
      Top = 144
      Width = 27
      Height = 44
      Caption = #44536#47532#44592
      TabOrder = 13
      WordWrap = True
      OnClick = Button8Click
    end
    object Edit17: TEdit
      Left = 17
      Top = 165
      Width = 32
      Height = 23
      TabOrder = 14
      TextHint = #48176#49688
    end
  end
  object Edit15: TEdit
    Left = 316
    Top = 3
    Width = 66
    Height = 23
    TabOrder = 7
    Text = '5'
    OnChange = Edit15Change
  end
  object SavePictureDialog1: TSavePictureDialog
    Left = 432
    Top = 312
  end
end
