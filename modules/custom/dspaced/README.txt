ABOUT DSPACED
-------------

DSpaced provides a set of default Feeds importers that can be used
to import items from a DSpace repository using the DSpace REST API.

WARNING: DSpaced has been tested with a max number of 2000 items
per community, and with less than 10 communities.

CONFIGURATION
-------------
Summary of configuration steps:
 * Configure cron or poor mans cron.
 * Configure connection to DSpace repository REST API.
 * Choose communities to import items from.

Settings can be found on the module configuration page
/admin/config/dspaced/settings. You can set the base url of the
DSpace repository's REST API and choose which communities you
want to import items from.

 * Enter the base URL of the DSpace repository REST API
   e.g. http://example.com/rest
 * Save configuration: a HTTP request is made to the repository to
   check the connection using default importer dspaced_communities
   which calls /communities.xml.
   If connection is successful a list of available communities
   is returned with checkboxes.
 * Select the communities you want to import items from.
 * Save configuration: For each selected community the community's
   details are imported using default importer dspaced_community
   which calls /communities/:id.xml, and a community node is
   created (default uses dspaced_entites_community node type)

If you deselect a community and save configuration the community's
node and all it's imported items will be deleted.

IMPORTING ITEMS
---------------
After selecting a community all item imports are scheduled
automatically. You can manually bulk import items by visiting
the import tab on a community node, only dspace entity ids are
imported. To manually import the full data for an existing item
use the import tab on the item node.

Each community node is itself a feeds source and uses the default
importer dspaced_harvest which calls /harvest.xml?idOnly=true&community=:id
to retrieve DSpace entity IDs for each item in the community.
It creates a blank node for each item ID it retrieves (default
node type is dspaced_entities_item).

Each item node is itself a feeds source and uses the default
importer dspaced_item which calls /items/:id.xml with and uses
FeedsSelfNodeProcessor to update itself.

Feeds uses Job Scheduler and the core Queue for scheduling and
processing imports and deletions. Job Scheduler seems to put a
maximum of 200 feed import jobs in the queue on a cron run.
According to Job Scheduler README "Job Scheduler reserves a job
for one hour giving the queue time to work off a job before it
reschedules it..." unless a worker "...reset[s] the job's schedule
flag in order to allow renewed scheduling...". Feeds workers will
spend 15 seconds on each queue, each time cron is run. The
minimum frequency for poor mans cron is one hour. The default
time between execution of periodic imports set in dspaced importers
tries to make sense of these parameters but some tweaking to find
the optimum settings is recommended.

It may take a few cron runs to complete the import of items
after first selecting a community because the following steps are
being taken in the background:

  1. Community node is created.
  2. Harvest import job schedule is added for each community
     node with next execution some period in the future.
  3. Harvest import job is force triggered on an after community
     import hook.
  4. Empty item nodes are created for each item in the harvest results
     (but only if a node with that item's DSpace entity ID does not
     already exist).
  5. An item import job schedule is added for each new item node.
  6. Harvest import job schedule last execution time is updated
     (scheduler will add it to the queue some time in the future and
     a worker will pick it up some time after that to fetch community
     items and add any new ones repeating steps 4-6).
  7. Some time in the future, on cron, Job Scheduler adds the item
     import jobs to the Feeds import queue (seems a maximum of 200
     are added each cron run).
  8. Some time in the future, on cron, worker picks up item import
     job from queue.
  9. Item node is updated (item only updated if it has changed).
 10. Item import schedule last execution time is updated (scheduler
     will add the item import job back to the queue some time in the
     future and a worker will pick it up from the queue some time after
     that repeating steps 8-10).

NOTE: Prioritising empty item nodes from recent harvests would be
ideal but there is no way to do that at the moment. You can instead
increase the frequency of dspace_item imports when you first import
items from a community so that they get added to the queue quicker
then slow it down again once the majority of items are in the queue
to get their full data.


DELETING ITEMS
--------------
To remove all item nodes imported from a community and the
community node simply deselect the community from the module
settings. To keep the community node and just delete it's
imported items you can use the delete items tab on the
community node.

Deletion of items happens in the background, and may take a
few cron runs to complete.
