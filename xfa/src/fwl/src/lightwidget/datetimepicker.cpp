// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "../../../foxitlib.h"
CFWL_DateTimePicker* CFWL_DateTimePicker::Create() {
  return new CFWL_DateTimePicker;
}
FWL_ERR CFWL_DateTimePicker::Initialize(
    const CFWL_WidgetProperties* pProperties) {
  _FWL_RETURN_VALUE_IF_FAIL(!m_pIface, FWL_ERR_Indefinite);
  if (pProperties) {
    *m_pProperties = *pProperties;
  }
  CFWL_WidgetImpProperties prop;
  prop.m_dwStyles = m_pProperties->m_dwStyles;
  prop.m_dwStyleExes = m_pProperties->m_dwStyleExes;
  prop.m_dwStates = m_pProperties->m_dwStates;
  prop.m_ctmOnParent = m_pProperties->m_ctmOnParent;
  prop.m_pDataProvider = &m_DateTimePickerDP;
  if (m_pProperties->m_pParent) {
    prop.m_pParent = m_pProperties->m_pParent->GetWidget();
  }
  if (m_pProperties->m_pOwner) {
    prop.m_pOwner = m_pProperties->m_pOwner->GetWidget();
  }
  prop.m_rtWidget = m_pProperties->m_rtWidget;
  m_pIface = IFWL_DateTimePicker::Create();
  FWL_ERR ret = ((IFWL_DateTimePicker*)m_pIface)->Initialize(prop);
  if (ret == FWL_ERR_Succeeded) {
    CFWL_Widget::Initialize();
  }
  return ret;
}
FWL_ERR CFWL_DateTimePicker::SetToday(int32_t iYear,
                                      int32_t iMonth,
                                      int32_t iDay) {
  m_DateTimePickerDP.m_iYear = iYear;
  m_DateTimePickerDP.m_iMonth = iMonth;
  m_DateTimePickerDP.m_iDay = iDay;
  return FWL_ERR_Succeeded;
}
int32_t CFWL_DateTimePicker::CountSelRanges() {
  return ((IFWL_DateTimePicker*)m_pIface)->CountSelRanges();
}
int32_t CFWL_DateTimePicker::GetSelRange(int32_t nIndex, int32_t& nStart) {
  return ((IFWL_DateTimePicker*)m_pIface)->GetSelRange(nIndex, nStart);
}
FWL_ERR CFWL_DateTimePicker::GetEditText(CFX_WideString& wsText) {
  return ((IFWL_DateTimePicker*)m_pIface)->GetEditText(wsText);
}
FWL_ERR CFWL_DateTimePicker::SetEditText(const CFX_WideStringC& wsText) {
  return ((IFWL_DateTimePicker*)m_pIface)->SetEditText(wsText);
}
FWL_ERR CFWL_DateTimePicker::GetCurSel(int32_t& iYear,
                                       int32_t& iMonth,
                                       int32_t& iDay) {
  return ((IFWL_DateTimePicker*)m_pIface)->GetCurSel(iYear, iMonth, iDay);
}
FWL_ERR CFWL_DateTimePicker::SetCurSel(int32_t iYear,
                                       int32_t iMonth,
                                       int32_t iDay) {
  return ((IFWL_DateTimePicker*)m_pIface)->SetCurSel(iYear, iMonth, iDay);
}
CFWL_DateTimePicker::CFWL_DateTimePicker() {}
CFWL_DateTimePicker::~CFWL_DateTimePicker() {}
CFWL_DateTimePicker::CFWL_DateTimePickerDP::CFWL_DateTimePickerDP() {
  m_iYear = 2011;
  m_iMonth = 1;
  m_iDay = 1;
}
FWL_ERR CFWL_DateTimePicker::CFWL_DateTimePickerDP::GetCaption(
    IFWL_Widget* pWidget,
    CFX_WideString& wsCaption) {
  wsCaption = m_wsData;
  return FWL_ERR_Succeeded;
}
FWL_ERR CFWL_DateTimePicker::CFWL_DateTimePickerDP::GetToday(
    IFWL_Widget* pWidget,
    int32_t& iYear,
    int32_t& iMonth,
    int32_t& iDay) {
  iYear = m_iYear;
  iMonth = m_iMonth;
  iDay = m_iDay;
  return FWL_ERR_Succeeded;
}
FX_BOOL CFWL_DateTimePicker::CanUndo() {
  return ((IFWL_DateTimePicker*)m_pIface)->CanUndo();
}
FX_BOOL CFWL_DateTimePicker::CanRedo() {
  return ((IFWL_DateTimePicker*)m_pIface)->CanRedo();
}
FX_BOOL CFWL_DateTimePicker::Undo() {
  return ((IFWL_DateTimePicker*)m_pIface)->Undo();
}
FX_BOOL CFWL_DateTimePicker::Redo() {
  return ((IFWL_DateTimePicker*)m_pIface)->Redo();
}
FX_BOOL CFWL_DateTimePicker::CanCopy() {
  return ((IFWL_DateTimePicker*)m_pIface)->CanCopy();
}
FX_BOOL CFWL_DateTimePicker::CanCut() {
  return ((IFWL_DateTimePicker*)m_pIface)->CanCut();
}
FX_BOOL CFWL_DateTimePicker::CanSelectAll() {
  return ((IFWL_DateTimePicker*)m_pIface)->CanSelectAll();
}
FX_BOOL CFWL_DateTimePicker::Copy(CFX_WideString& wsCopy) {
  return ((IFWL_DateTimePicker*)m_pIface)->Copy(wsCopy);
}
FX_BOOL CFWL_DateTimePicker::Cut(CFX_WideString& wsCut) {
  return ((IFWL_DateTimePicker*)m_pIface)->Copy(wsCut);
}
FX_BOOL CFWL_DateTimePicker::Paste(const CFX_WideString& wsPaste) {
  return ((IFWL_DateTimePicker*)m_pIface)->Paste(wsPaste);
}
FX_BOOL CFWL_DateTimePicker::SelectAll() {
  return ((IFWL_DateTimePicker*)m_pIface)->SelectAll();
}
FX_BOOL CFWL_DateTimePicker::Delete() {
  return ((IFWL_DateTimePicker*)m_pIface)->Delete();
}
FX_BOOL CFWL_DateTimePicker::DeSelect() {
  return ((IFWL_DateTimePicker*)m_pIface)->DeSelect();
}
FWL_ERR CFWL_DateTimePicker::GetBBox(CFX_RectF& rect) {
  return ((IFWL_DateTimePicker*)m_pIface)->GetBBox(rect);
}
FWL_ERR CFWL_DateTimePicker::SetEditLimit(int32_t nLimit) {
  return ((IFWL_DateTimePicker*)m_pIface)->SetEditLimit(nLimit);
}
FWL_ERR CFWL_DateTimePicker::ModifyEditStylesEx(FX_DWORD dwStylesExAdded,
                                                FX_DWORD dwStylesExRemoved) {
  return ((IFWL_DateTimePicker*)m_pIface)
      ->ModifyEditStylesEx(dwStylesExAdded, dwStylesExRemoved);
}
