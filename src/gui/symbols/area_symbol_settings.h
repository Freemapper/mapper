/*
 *    Copyright 2012, 2013 Thomas Schöps
 *    Copyright 2012-2017 Kai Pastor
 *
 *    This file is part of OpenOrienteering.
 *
 *    OpenOrienteering is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    OpenOrienteering is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with OpenOrienteering.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef OPENORIENTEERING_AREA_SYMBOL_SETTINGS_H
#define OPENORIENTEERING_AREA_SYMBOL_SETTINGS_H

#include "gui/symbols/symbol_properties_widget.h"

#include "core/symbols/area_symbol.h"

QT_BEGIN_NAMESPACE
class QCheckBox;
class QDoubleSpinBox;
class QLabel;
class QListWidget;
class QPushButton;
class QSpinBox;
class QToolButton;
class QXmlStreamReader;
class QXmlStreamWriter;
QT_END_NAMESPACE

class ColorDropDown;
class SymbolSettingDialog;
class PointSymbolEditorWidget;
class PathObject;
class PointObject;
class LineSymbol;
class PointSymbol;
class SymbolPropertiesWidget;
class SymbolSettingDialog;
class MapEditorController;

class AreaSymbolSettings : public SymbolPropertiesWidget
{
Q_OBJECT
public:
	AreaSymbolSettings(AreaSymbol* symbol, SymbolSettingDialog* dialog);
	
	virtual void reset(Symbol* symbol);
	
	/**
	 * Updates the general area fields (not related to patterns)
	 */
	void updateAreaGeneral();
	
	void addPattern(AreaSymbol::FillPattern::Type type);
	
signals:
	void switchPatternEdits(int layer);
	
public slots:
	void selectPattern(int index);
	void addLinePattern();
	void addPointPattern();
	void deleteActivePattern();
	
protected:
	void clearPatterns();
	void loadPatterns();
	void updatePatternNames();
	void updatePatternWidgets();
	
protected slots:
	void colorChanged();
	void minimumSizeChanged(double value);
	void patternAngleChanged(double value);
	void patternRotatableClicked(bool checked);
	void patternSpacingChanged(double value);
	void patternLineOffsetChanged(double value);
	void patternOffsetAlongLineChanged(double value);
	void patternColorChanged();
	void patternLineWidthChanged(double value);
	void patternPointDistChanged(double value);
	
private:
	AreaSymbol* symbol;
	Map* map;
	MapEditorController* controller;
	std::vector<AreaSymbol::FillPattern>::iterator active_pattern;
	
	ColorDropDown*  color_edit;
	QDoubleSpinBox* minimum_size_edit;
	
	QListWidget*    pattern_list;
	QToolButton*    add_pattern_button;
	QPushButton*    del_pattern_button;
	
	QLabel*         pattern_name_edit;
	QDoubleSpinBox* pattern_angle_edit;
	QCheckBox*      pattern_rotatable_check;
	QDoubleSpinBox* pattern_spacing_edit;
	QDoubleSpinBox* pattern_line_offset_edit;
	QDoubleSpinBox* pattern_offset_along_line_edit;
	
	ColorDropDown*  pattern_color_edit;
	QDoubleSpinBox* pattern_linewidth_edit;
	QDoubleSpinBox* pattern_pointdist_edit;
};

#endif
