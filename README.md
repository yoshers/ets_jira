# UC Berkeley ETS JIRA module for Open Berkeley (Drupal 7.x)

*   [Purpose]("#purpose")
*   [Requirements](#requirements)
*   [Configuration Details](#configuration_details)
    * [Module Configurations](#module_configurations)
    * [Webform Configurations](#webform_configurations)
*   [Authors](#authors)

<a name="purpose">
# Purpose #
</a>
This is a specially written module to allow for Open Berkeley Drupal 7.x webforms to be integrated with Atlassian Jira. The module uses SOAP for the connection (note: SOAP for Jira is known to be deprecated and will NOT work for Atlassian 7.x and beyond).

When a web form with Jira integration is submitted, the default behavior is for the module to process the inputs and create a Jira ticket at the desired Jira instance (configurable in the ETS Jira module configuration page). If the module detects a failure during the ticket create process, it will then attempt to send an email to the appropriate address so that Jira can then ingest the email and create a ticket in that manner.

<a name="requirements">
# Requirements #
</a>
You need the following modules installed:

* [Webforms](http://drupal.org/project/webforms)
* [Chaos Tools](http://drupal.org/project/ctools)
* [Views](http://drupal.org/project/views)
* [UC Berkeley CAS 7](https://github.com/bwood/ucberkeley_cas-7/releases)

<a name="configuration_details">
# Configuration Details #
</a>
There are two sets of configurations to consider when implementating this module.
<a name="module_configurations">
# Module Configurations #
</a>
The Module wide configurations can be found in <b>/admin/settings/ets_jira/</b>. They include the following options:

* ETS Jira Server SOAP WSDL URL (URL to the SOAP WSDL for the Jira server)
* ETS Jira Username
* ETS Jira Password
* ETS Jira Error Email Recipient (this is a module wide email address; primary use is for troubleshooting the module by the developer or systems administrator)
* [Checkbox] ETS Jira - Send Backup Email? (this is an option to turn off Backup Emails for the module - this will disallow sending of email to the backup email address for Jira ticket creation; default is <b>CHECKED</b> and should be checked for production usage

<a name="webform_configurations">
# Webform Configurations #
</a>
Firstly, here are the REQUIRED Hidden fields that is used by the module to decide which project/priority/type to set in the Jira instance when the webform is submitted:

Label | Type | Value/Example Value (Explanation of field usage)
* ETS Jira | Hidden | 1 (Tells the module that this is a webform that should be submitted to Jira)
* ETS Jira Project | Hidden | CNVS (Jira Project to submit form)
* ETS Jira Reporter | Hidden | ets_form (Jira user for ticket reporter field)
* ETS Jira Priority | Hidden | 3 (Jira ticket priority field)
* ETS Jira Type | Hidden | 15 (Jira ticket type field)
* ETS Jira Component | Hidden | 12748 (Jira ticket component field)
* ETS Jira Section Header | Hidden | bCourses Support Request (Second half of the Jira description field; first half is full name of ticket submitter)
* ETS Jira Backup Email | Hidden | bcourseshelp@berkeley.edu (email address to send submission if Jira ticket creation fails)

Secondly, here are the REQUIRED basic user/ticket information that should be included in the webform (note that the value of some of these fields uses LDAP info that is grabbed via CalNet directory):

Label | Type | Value/Example Value (Explanation of field usage)
* Name | Textfield | [current-user:cas:ldap:displayname]
* Department | Textfield | [current-user:cas:ldap:berkeleyeduunithrdeptname]
* Phone | Textfield | [current-user:cas:ldap:telephonenumber]
* Email | Textfield | [current-user:cas:ldap:mail]
* Role | Select Options | Faculty/GSI/Student/Other
* UID | Hidden | [current-user:cas:ldap:uid]
* Department Relationship | Hidden | [current-user:cas:ldap:berkeleyeduprimarydeptunithierarchystring] (LDAP info may be incomplete due to LDAP module bug that only returns one affiliation per user)
* Affiliation Type | Hidden | [current-user:cas:ldap:berkeleyeduaffiliations] (LDAP info may be incomplete due to LDAP module bug that only returns one affiliation per user)
* Description | Textarea |

There is also an optional "select service" label that you can use to provide a list of options which allows for the ticket creation to include an additional Jira component input. Here is an example of how this label might be set up:

* Label - "Select Service"
* Field Key - "select_service"
* Options
  * 13245|Academic Integrity (Turnitin)
  * 13240|Audience Response (iClicker)
  * 12660|bCourses (Canvas)

Note that the key - value pair in the options corresponds to "Jira component|Webform display name".

Finally, you can add any additional labels in the webform. The input for those items will be dumped in to the "Description" field when the Jira ticket is created.

<a name="authors">
# Authors #
</a>
Kevin Chan
