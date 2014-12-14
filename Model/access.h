/**************************************************************************
**   File: access.h
**   Created on: Sat Dec 13 21:50:44 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef ACCESS_H
#define ACCESS_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class Access  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	Access();
	Access(QString Title,bool Company,bool Tax,bool Contact,bool ContactTelephone,bool ContactEmail,bool BankAccount,bool ContactClass,bool ContactType,bool Country,bool Currency,bool ContactStatus,bool FieldType,bool ContactField,bool ContactFieldData,bool ContactPersonField,bool ContactPersonFieldData,bool ContactPerson,bool ContactPersonTelephone,bool ContactPersonEmail,bool ProjectStatus,bool Project,bool ProjectFile,bool ProjectContactPerson,bool ProjectProduct,bool ProjectService,bool Unit,bool ProductCategory,bool ProductImage,bool Product,bool ProductField,bool ProductFieldData,bool Service,bool Store,bool PurchaseStatus,bool PurchaseSerial,bool Purchase,bool PurchaseStoreProduct,bool PurchaseFreeLine,bool DeliveryOrderStatus,bool DeliveryOrder,bool DeliveryOrderStoreProduct,bool DeliveryOrderService,bool DeliveryOrderFreeline,bool InvoicePeriod,bool InvoiceYear,bool InvoiceState,bool InvoiceSerial,bool Invoice,bool InvoiceStateD,bool InvoiceFreeline,bool PaymentType,bool Payment,bool Task,bool TimeBooking,QString hashKey,int EmployeeID,QString CreatedOn,QString EditedOn);	int AccessID;
	QString Title;
	bool Company;
	bool Tax;
	bool Contact;
	bool ContactTelephone;
	bool ContactEmail;
	bool BankAccount;
	bool ContactClass;
	bool ContactType;
	bool Country;
	bool Currency;
	bool ContactStatus;
	bool FieldType;
	bool ContactField;
	bool ContactFieldData;
	bool ContactPersonField;
	bool ContactPersonFieldData;
	bool ContactPerson;
	bool ContactPersonTelephone;
	bool ContactPersonEmail;
	bool ProjectStatus;
	bool Project;
	bool ProjectFile;
	bool ProjectContactPerson;
	bool ProjectProduct;
	bool ProjectService;
	bool Unit;
	bool ProductCategory;
	bool ProductImage;
	bool Product;
	bool ProductField;
	bool ProductFieldData;
	bool Service;
	bool Store;
	bool PurchaseStatus;
	bool PurchaseSerial;
	bool Purchase;
	bool PurchaseStoreProduct;
	bool PurchaseFreeLine;
	bool DeliveryOrderStatus;
	bool DeliveryOrder;
	bool DeliveryOrderStoreProduct;
	bool DeliveryOrderService;
	bool DeliveryOrderFreeline;
	bool InvoicePeriod;
	bool InvoiceYear;
	bool InvoiceState;
	bool InvoiceSerial;
	bool Invoice;
	bool InvoiceStateD;
	bool InvoiceFreeline;
	bool PaymentType;
	bool Payment;
	bool Task;
	bool TimeBooking;
	QString hashKey;
	int EmployeeID;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	Access* get();
	Access* get(const QModelIndex &index);
	static Access* Get(int id);
	static Access* Get(QString name);
	static QList<Access*> GetAll();
	static QList<Access*> Search(QString keyword);
	static QList<Access*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<Access*> accesss);
	static int GetIndex(QString title);
	static Access* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Access(int AccessID,QString Title,bool Company,bool Tax,bool Contact,bool ContactTelephone,bool ContactEmail,bool BankAccount,bool ContactClass,bool ContactType,bool Country,bool Currency,bool ContactStatus,bool FieldType,bool ContactField,bool ContactFieldData,bool ContactPersonField,bool ContactPersonFieldData,bool ContactPerson,bool ContactPersonTelephone,bool ContactPersonEmail,bool ProjectStatus,bool Project,bool ProjectFile,bool ProjectContactPerson,bool ProjectProduct,bool ProjectService,bool Unit,bool ProductCategory,bool ProductImage,bool Product,bool ProductField,bool ProductFieldData,bool Service,bool Store,bool PurchaseStatus,bool PurchaseSerial,bool Purchase,bool PurchaseStoreProduct,bool PurchaseFreeLine,bool DeliveryOrderStatus,bool DeliveryOrder,bool DeliveryOrderStoreProduct,bool DeliveryOrderService,bool DeliveryOrderFreeline,bool InvoicePeriod,bool InvoiceYear,bool InvoiceState,bool InvoiceSerial,bool Invoice,bool InvoiceStateD,bool InvoiceFreeline,bool PaymentType,bool Payment,bool Task,bool TimeBooking,QString hashKey,int EmployeeID,QString CreatedOn,QString EditedOn);	static Access* p_instance;
	bool setTitle(int AccessID, const QString &Title);
	bool setCompany(int AccessID, const QString &Company);
	bool setTax(int AccessID, const QString &Tax);
	bool setContact(int AccessID, const QString &Contact);
	bool setContactTelephone(int AccessID, const QString &ContactTelephone);
	bool setContactEmail(int AccessID, const QString &ContactEmail);
	bool setBankAccount(int AccessID, const QString &BankAccount);
	bool setContactClass(int AccessID, const QString &ContactClass);
	bool setContactType(int AccessID, const QString &ContactType);
	bool setCountry(int AccessID, const QString &Country);
	bool setCurrency(int AccessID, const QString &Currency);
	bool setContactStatus(int AccessID, const QString &ContactStatus);
	bool setFieldType(int AccessID, const QString &FieldType);
	bool setContactField(int AccessID, const QString &ContactField);
	bool setContactFieldData(int AccessID, const QString &ContactFieldData);
	bool setContactPersonField(int AccessID, const QString &ContactPersonField);
	bool setContactPersonFieldData(int AccessID, const QString &ContactPersonFieldData);
	bool setContactPerson(int AccessID, const QString &ContactPerson);
	bool setContactPersonTelephone(int AccessID, const QString &ContactPersonTelephone);
	bool setContactPersonEmail(int AccessID, const QString &ContactPersonEmail);
	bool setProjectStatus(int AccessID, const QString &ProjectStatus);
	bool setProject(int AccessID, const QString &Project);
	bool setProjectFile(int AccessID, const QString &ProjectFile);
	bool setProjectContactPerson(int AccessID, const QString &ProjectContactPerson);
	bool setProjectProduct(int AccessID, const QString &ProjectProduct);
	bool setProjectService(int AccessID, const QString &ProjectService);
	bool setUnit(int AccessID, const QString &Unit);
	bool setProductCategory(int AccessID, const QString &ProductCategory);
	bool setProductImage(int AccessID, const QString &ProductImage);
	bool setProduct(int AccessID, const QString &Product);
	bool setProductField(int AccessID, const QString &ProductField);
	bool setProductFieldData(int AccessID, const QString &ProductFieldData);
	bool setService(int AccessID, const QString &Service);
	bool setStore(int AccessID, const QString &Store);
	bool setPurchaseStatus(int AccessID, const QString &PurchaseStatus);
	bool setPurchaseSerial(int AccessID, const QString &PurchaseSerial);
	bool setPurchase(int AccessID, const QString &Purchase);
	bool setPurchaseStoreProduct(int AccessID, const QString &PurchaseStoreProduct);
	bool setPurchaseFreeLine(int AccessID, const QString &PurchaseFreeLine);
	bool setDeliveryOrderStatus(int AccessID, const QString &DeliveryOrderStatus);
	bool setDeliveryOrder(int AccessID, const QString &DeliveryOrder);
	bool setDeliveryOrderStoreProduct(int AccessID, const QString &DeliveryOrderStoreProduct);
	bool setDeliveryOrderService(int AccessID, const QString &DeliveryOrderService);
	bool setDeliveryOrderFreeline(int AccessID, const QString &DeliveryOrderFreeline);
	bool setInvoicePeriod(int AccessID, const QString &InvoicePeriod);
	bool setInvoiceYear(int AccessID, const QString &InvoiceYear);
	bool setInvoiceState(int AccessID, const QString &InvoiceState);
	bool setInvoiceSerial(int AccessID, const QString &InvoiceSerial);
	bool setInvoice(int AccessID, const QString &Invoice);
	bool setInvoiceStateD(int AccessID, const QString &InvoiceStateD);
	bool setInvoiceFreeline(int AccessID, const QString &InvoiceFreeline);
	bool setPaymentType(int AccessID, const QString &PaymentType);
	bool setPayment(int AccessID, const QString &Payment);
	bool setTask(int AccessID, const QString &Task);
	bool setTimeBooking(int AccessID, const QString &TimeBooking);
	bool sethashKey(int AccessID, const QString &hashKey);
	bool setEmployeeID(int AccessID, const QString &EmployeeID);
	bool setCreatedOn(int AccessID, const QString &CreatedOn);
	bool setEditedOn(int AccessID, const QString &EditedOn);

};
#endif
