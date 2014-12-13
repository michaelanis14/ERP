/**************************************************************************
**   File: access.h
**   Created on: Sat Dec 13 13:51:05 EET 2014
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
	Access(QString Title,bool Tax,bool Employee,bool Contact,bool ContactTelephone,bool ContactEmail,bool BankAccount,bool ContactClass,bool ContactType,bool Country,bool Currency,bool ContactStatus,bool FieldType,bool ContactField,bool ContactFieldData,bool ContactPersonField,bool ContactPersonFieldData,bool ContactPerson,bool ContactPersonTelephone,bool ContactPersonEmail,bool ProjectStatus,bool Project,bool ProjectFile,bool ProjectContactPerson,bool ProjectProduct,bool ProjectService,bool Unit,bool ProductCategory,bool ProductImage,bool Product,bool ProductField,bool ProductFieldData,bool Service,bool Store,bool PurchaseStatus,bool PurchaseSerial,bool Purchase,bool PurchaseStoreProduct,bool PurchaseFreeLine,bool DeliveryOrderStatus,bool DeliveryOrder,bool DeliveryOrderStoreProduct,bool DeliveryOrderService,bool DeliveryOrderFreeline,bool InvoicePeriod,bool InvoiceYear,bool InvoiceState,bool InvoiceSerial,bool Invoice,bool InvoiceStateDate,bool InvoiceFreeline,bool PaymentType,bool Payment,bool Task,bool TimeBooking,QString hashKey,int EmployeeID,QString CreatedON,QString EditedON);	bool Company;
	QString Title;
	bool Tax;
	bool Employee;
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
	bool InvoiceStateDate;
	bool InvoiceFreeline;
	bool PaymentType;
	bool Payment;
	bool Task;
	bool TimeBooking;
	QString hashKey;
	int EmployeeID;
	QString CreatedON;
	QString EditedON;
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
	Access(bool Company,QString Title,bool Tax,bool Employee,bool Contact,bool ContactTelephone,bool ContactEmail,bool BankAccount,bool ContactClass,bool ContactType,bool Country,bool Currency,bool ContactStatus,bool FieldType,bool ContactField,bool ContactFieldData,bool ContactPersonField,bool ContactPersonFieldData,bool ContactPerson,bool ContactPersonTelephone,bool ContactPersonEmail,bool ProjectStatus,bool Project,bool ProjectFile,bool ProjectContactPerson,bool ProjectProduct,bool ProjectService,bool Unit,bool ProductCategory,bool ProductImage,bool Product,bool ProductField,bool ProductFieldData,bool Service,bool Store,bool PurchaseStatus,bool PurchaseSerial,bool Purchase,bool PurchaseStoreProduct,bool PurchaseFreeLine,bool DeliveryOrderStatus,bool DeliveryOrder,bool DeliveryOrderStoreProduct,bool DeliveryOrderService,bool DeliveryOrderFreeline,bool InvoicePeriod,bool InvoiceYear,bool InvoiceState,bool InvoiceSerial,bool Invoice,bool InvoiceStateDate,bool InvoiceFreeline,bool PaymentType,bool Payment,bool Task,bool TimeBooking,QString hashKey,int EmployeeID,QString CreatedON,QString EditedON);	static Access* p_instance;
	bool setTitle(bool Company, const QString &Title);
	bool setTax(bool Company, const QString &Tax);
	bool setEmployee(bool Company, const QString &Employee);
	bool setContact(bool Company, const QString &Contact);
	bool setContactTelephone(bool Company, const QString &ContactTelephone);
	bool setContactEmail(bool Company, const QString &ContactEmail);
	bool setBankAccount(bool Company, const QString &BankAccount);
	bool setContactClass(bool Company, const QString &ContactClass);
	bool setContactType(bool Company, const QString &ContactType);
	bool setCountry(bool Company, const QString &Country);
	bool setCurrency(bool Company, const QString &Currency);
	bool setContactStatus(bool Company, const QString &ContactStatus);
	bool setFieldType(bool Company, const QString &FieldType);
	bool setContactField(bool Company, const QString &ContactField);
	bool setContactFieldData(bool Company, const QString &ContactFieldData);
	bool setContactPersonField(bool Company, const QString &ContactPersonField);
	bool setContactPersonFieldData(bool Company, const QString &ContactPersonFieldData);
	bool setContactPerson(bool Company, const QString &ContactPerson);
	bool setContactPersonTelephone(bool Company, const QString &ContactPersonTelephone);
	bool setContactPersonEmail(bool Company, const QString &ContactPersonEmail);
	bool setProjectStatus(bool Company, const QString &ProjectStatus);
	bool setProject(bool Company, const QString &Project);
	bool setProjectFile(bool Company, const QString &ProjectFile);
	bool setProjectContactPerson(bool Company, const QString &ProjectContactPerson);
	bool setProjectProduct(bool Company, const QString &ProjectProduct);
	bool setProjectService(bool Company, const QString &ProjectService);
	bool setUnit(bool Company, const QString &Unit);
	bool setProductCategory(bool Company, const QString &ProductCategory);
	bool setProductImage(bool Company, const QString &ProductImage);
	bool setProduct(bool Company, const QString &Product);
	bool setProductField(bool Company, const QString &ProductField);
	bool setProductFieldData(bool Company, const QString &ProductFieldData);
	bool setService(bool Company, const QString &Service);
	bool setStore(bool Company, const QString &Store);
	bool setPurchaseStatus(bool Company, const QString &PurchaseStatus);
	bool setPurchaseSerial(bool Company, const QString &PurchaseSerial);
	bool setPurchase(bool Company, const QString &Purchase);
	bool setPurchaseStoreProduct(bool Company, const QString &PurchaseStoreProduct);
	bool setPurchaseFreeLine(bool Company, const QString &PurchaseFreeLine);
	bool setDeliveryOrderStatus(bool Company, const QString &DeliveryOrderStatus);
	bool setDeliveryOrder(bool Company, const QString &DeliveryOrder);
	bool setDeliveryOrderStoreProduct(bool Company, const QString &DeliveryOrderStoreProduct);
	bool setDeliveryOrderService(bool Company, const QString &DeliveryOrderService);
	bool setDeliveryOrderFreeline(bool Company, const QString &DeliveryOrderFreeline);
	bool setInvoicePeriod(bool Company, const QString &InvoicePeriod);
	bool setInvoiceYear(bool Company, const QString &InvoiceYear);
	bool setInvoiceState(bool Company, const QString &InvoiceState);
	bool setInvoiceSerial(bool Company, const QString &InvoiceSerial);
	bool setInvoice(bool Company, const QString &Invoice);
	bool setInvoiceStateDate(bool Company, const QString &InvoiceStateDate);
	bool setInvoiceFreeline(bool Company, const QString &InvoiceFreeline);
	bool setPaymentType(bool Company, const QString &PaymentType);
	bool setPayment(bool Company, const QString &Payment);
	bool setTask(bool Company, const QString &Task);
	bool setTimeBooking(bool Company, const QString &TimeBooking);
	bool sethashKey(bool Company, const QString &hashKey);
	bool setEmployeeID(bool Company, const QString &EmployeeID);
	bool setCreatedON(bool Company, const QString &CreatedON);
	bool setEditedON(bool Company, const QString &EditedON);

};
#endif
